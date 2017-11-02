#include "BinarySearchTree.hpp"
#include <iostream>
#include <cassert>

using namespace DSA;

template <typename ObjectT>
bool BinarySearchTree<ObjectT>::insertAt(Node& node, const ObjectT& obj) {

  if (obj < node.m_data) {
     if ( ! node.hasLeft()) {
         node.m_left_child.reset(new Node(obj));
         return true;
     }
     else
         return insertAt(*(node.m_left_child),obj);
  }
  else if (obj > node.m_data) {
     if (! node.hasRight()) {
         node.m_right_child.reset(new Node(obj));
         return true;
     }
     else 
         return insertAt(*(node.m_right_child),obj);
  }
  else {
      throw (std::domain_error("BinarySearchTree does not support muliple elements with same key."));
  }

   return false;
}

template <typename ObjectT>
const ObjectT* BinarySearchTree<ObjectT>::findFrom(Node& node, const ObjectT& obj) const {
   // base
   
   if (node.m_data == obj) return &(node.m_data);
   else if (node.hasLeft() ? obj < node.m_data : false) findFrom(*(node.m_left_child),obj);
   else if (node.hasRight() ? obj > node.m_data : false) findFrom(*(node.m_right_child),obj);
   return nullptr;

}

template<typename ObjectT>
bool BinarySearchTree<ObjectT>::insert(const ObjectT& data) {
  if (!m_root.get()) {
     m_root.reset(new Node(data));
     return true;
  }
  return insertAt(*m_root,data); 
}

template <typename ObjectT>
const ObjectT* BinarySearchTree<ObjectT>::find(const ObjectT& ref) const {
   findFrom(*m_root,ref);
}

template <typename ObjectT>
ObjectT* BinarySearchTree<ObjectT>::find(const ObjectT& ref) {
    const ObjectT* found = static_cast<const BinarySearchTree<ObjectT>* >(this)->findFrom(*m_root,ref);
    return const_cast<ObjectT*>(found);
}


template <typename ObjectT>
void BinarySearchTree<ObjectT>::Node::print(int level) {
    for(int i=0;i<level;i++) {
       std::cout <<"\t";
    }
    std::cout << m_data << std::endl;
    auto null_print = [&]()->void{for(int i=0;i<level+1;i++) std::cout<<"\t"; std::cout<<"null"<<std::endl;};
   hasLeft() ? m_left_child->print(level +1) : null_print();
   hasRight()? m_right_child->print(level+1) : null_print(); 
}

// instantiating here because the .cpp file has function/class definitions

namespace DSA {
   template class BinarySearchTree<int>;
   //template<>
   //bool BinarySearchTree<int>::insert(int const&);
   //class BinarySearchTree<int>::Node;
   //void BinarySearchTree<int>::Node::print(int);
}
