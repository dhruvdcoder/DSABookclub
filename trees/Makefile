CC=g++
CXXFLAGS=-g -std=c++11 -c
LD=g++
LDFLAGS=-g -std=c++11

all:BinarySearchTreeDriver

BinarySearchTree:BinarySearchTree.cpp
	$(CC) $(CXXFLAGS) BinarySearchTree.cpp -o BinarySearchTree.o 

BinarySearchTreeDriver_c:BinarySearchTreeDriver.cpp
	$(CC) $(CXXFLAGS) BinarySearchTreeDriver.cpp -o BinarySearchTreeDriver.o

BinarySearchTreeDriver:BinarySearchTreeDriver_c BinarySearchTree
	$(LD) $(LDFLAGS) BinarySearchTree.o BinarySearchTreeDriver.o -o BinarySearchTreeDriver
