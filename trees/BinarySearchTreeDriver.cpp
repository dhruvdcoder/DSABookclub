#include "BinarySearchTree.hpp"

using namespace DSA;

int main() {

   BinarySearchTree<int> aSet;
   aSet.insert(1);
   aSet.insert(5);
   aSet.insert(3);
   aSet.insert(0);
   aSet.print();

   return 0;
}
