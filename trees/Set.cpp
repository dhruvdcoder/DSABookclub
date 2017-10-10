#include "Set.hpp"

using namespace DSA;

template <typename ObjectT>
bool Set::insertAt(SetNode<ObjectT>& node, const ObjectT& obj) {
   // Check for base case 
   if(node.isLeaf()) {
     if (obj < node.m_data) {
         node.m_left_child.reset(new SetNode(obj));
     }
     else if (obj > node.m_data) {
        node.m_right_child.reset(new SetNode(obj));
     }
     else {
         std::throw (std::domain_error("Set does not support muliple elements with same key."));
     }

     return true;
   }
   // recurse
   if      (obj < node.m_data) { return insertAt(*(node.m_left_child),obj);}
   else if (obj > node.m_data) { return insertAt(*(node.m_right_child),obj);}
   else                        { std::throw (std::domain_error("Set does not support muliple elements with same key."));}
   return false;
}

template <typename ObjectT>
ObjectT* Set::findFrom(SetNode<ObjectT>& node, const ObjectT& obj) {
   // base
   
   if (node.m_data == obj) return &(node.m_data);
   else if (node.hasLeft() ? obj < node.m_data : false) findFrom(*(node.m_left_child),obj);
   else if (node.hasRight() ? obj > node.m_data : false) findFrom(*(node.m_right_child),obj);
   return nullptr;

}

template<typename ObjectT>
bool Set::insert(const ObjectT& data) {
  return insertAt(*m_root,data); 
}

template <typename ObjectT>
bool Set::find(const ObjectT& ref) {
   findFrom(m_root,ref);
}
