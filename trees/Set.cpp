#include "Set.hpp"
#include <iostream>
#include <cassert>

using namespace DSA;

template <typename ObjectT>
bool Set<ObjectT>::insertAt(SetNode& node, const ObjectT& obj) {

  if (obj < node.m_data) {
     if ( ! node.hasLeft()) {
         node.m_left_child.reset(new SetNode(obj));
         return true;
     }
     else
         return insertAt(*(node.m_left_child),obj);
  }
  else if (obj > node.m_data) {
     if (! node.hasRight()) {
         node.m_right_child.reset(new SetNode(obj));
         return true;
     }
     else 
         return insertAt(*(node.m_right_child),obj);
  }
  else {
      throw (std::domain_error("Set does not support muliple elements with same key."));
  }

   return false;
}

template <typename ObjectT>
const ObjectT* Set<ObjectT>::findFrom(SetNode& node, const ObjectT& obj) const {
   // base
   
   if (node.m_data == obj) return &(node.m_data);
   else if (node.hasLeft() ? obj < node.m_data : false) findFrom(*(node.m_left_child),obj);
   else if (node.hasRight() ? obj > node.m_data : false) findFrom(*(node.m_right_child),obj);
   return nullptr;

}

template<typename ObjectT>
bool Set<ObjectT>::insert(const ObjectT& data) {
  if (!m_root.get()) {
     m_root.reset(new SetNode(data));
     return true;
  }
  return insertAt(*m_root,data); 
}

template <typename ObjectT>
const ObjectT* Set<ObjectT>::find(const ObjectT& ref) const {
   findFrom(*m_root,ref);
}

template <typename ObjectT>
ObjectT* Set<ObjectT>::find(const ObjectT& ref) {
    const ObjectT* found = static_cast<const Set<ObjectT>* >(this)->findFrom(*m_root,ref);
    return const_cast<ObjectT*>(found);
}


template <typename ObjectT>
void Set<ObjectT>::SetNode::print(int level) {
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
   template class Set<int>;
   //template<>
   //bool Set<int>::insert(int const&);
   //class Set<int>::SetNode;
   //void Set<int>::SetNode::print(int);
}
