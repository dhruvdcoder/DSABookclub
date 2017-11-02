#ifndef _BINARYSEARCHTREE_H_ 
#define _BINARYSEARCHTREE_H_
#include <memory>
/** @file Implements classes for set as a binay search tree 
 * @todo 1. Add iterator class for the set and use that as the return type for insert, find etc.
 *       2. Add support for move semantics
 */
namespace DSA {

   
 /** @brief A binary search tree based implementation of set.
 *
 * Supported operations:
 * 1. insert
 * 2. find
 * 3. remove
 *
 * 
 */
template<typename ObjectT>
class BinarySearchTree 
{
    struct Node 
    {
        public:
           ObjectT m_data;
           std::unique_ptr<Node> m_left_child;
           std::unique_ptr<Node> m_right_child;

           // constructor
           Node(const ObjectT& data):m_data(data){}
           //Node(ObjectT&& data):m_data(data){}
           //
           //destructor
           ~Node()=default;

           // helper functions
           bool isLeaf() { return !(m_left_child.get() || m_right_child.get());}
           bool hasLeft() { return m_left_child.get(); }
           bool hasRight() { return m_right_child.get(); }
           /* pre-order traversing print */
           void print(int level=0);
    };
    std::unique_ptr<Node> m_root;
    // keeping it un-assignable and non-copy constructible
    BinarySearchTree(const BinarySearchTree&);
    const BinarySearchTree& operator=(const BinarySearchTree&);

   private:
    // helper functions
    bool insertAt(Node& node, const ObjectT& obj);
    const ObjectT* findFrom(Node& node, const ObjectT& obj) const;
    //bool insertAt(Node<ObjectT>& node, ObjectT&& obj);

   public:
    BinarySearchTree()=default;
    bool insert(const ObjectT& data); // copy insert
    //bool insert(const ObjectT&& data); // move insert
    
    ObjectT* find(const ObjectT& ref);
    const ObjectT* find(const ObjectT& ref)const;

    //unique_ptr<ObjectT> remove(const ObjectT& ref);
    void print() { m_root->print();}

    
};
}
#endif //_SET_H

