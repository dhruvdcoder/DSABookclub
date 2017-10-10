#ifndef _SET_H_
#define _SET_H_

#include <memory>
namespace DSA {
/** @brief A binary search tree based implementation of set.
 *
 * Supported operations:
 * 1. insert
 * 2. find
 * 3. remove
 */
template<typename ObjectT>
class Set 
{
    struct SetNode 
    {
        public:
           ObjectT m_data;
           unique_ptr<SetNode> m_left_child;
           unique_ptr<SetNode> m_right_child;
    };
    unique_ptr<SetNode> m_root;
    // keeping it un-assignable and non-copy constructible
    Set(const Set&);
    const Set& operator=(const Set&);
   public:
    Set()=default;
    bool insert(const ObjectT& data); // copy insert
    bool insert(const ObjectT&& data); // move insert
    
    ObjectT& find(const ObjectT& ref);
    const ObjectT& find(const ObjectT& ref) const;

    ObjectT remove(

    
};
}
#endif //_SET_H

