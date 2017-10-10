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
   }
}

template<typename ObjectT>
bool Set::insert(const ObjectT& data) {
   

}
