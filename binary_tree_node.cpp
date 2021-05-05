//----------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                             //
// Project: 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                  //
// Due Date: April 11, 2021                                                         //
//----------------------------------------------------------------------------------//

#include "binary_tree_node.h"
#include <iostream>

template<class T>
BTreeNode<T>::BTreeNode(){
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

template<class T>
BTreeNode<T>::BTreeNode(const T& anItem){
    item = anItem;
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

template<class T>
BTreeNode<T>::BTreeNode(const T& anItem, BTreeNode<T>* left, BTreeNode<T>* right){
    item = anItem;
    leftChildPtr = left;
    rightChildPtr = right;
}

template<class T>
void BTreeNode<T>::setItem(const T& anItem){
    item = anItem;
}

template<class T>
T BTreeNode<T>::getItem() const{
    return item;
}

template<class T>
bool BTreeNode<T>::isLeaf() const{
    // check if ( ) is needed around later if error pop up
    return leftChildPtr == nullptr && rightChildPtr == nullptr;
}

template<class T>
BTreeNode<T>* BTreeNode<T>::getLeftChildPtr() const{
    return leftChildPtr;
}

template<class T>
BTreeNode<T>* BTreeNode<T>::getRightChildPtr() const{
    return rightChildPtr;
}

template<class T>
void BTreeNode<T>::setLeftChildPtr(BTreeNode<T>* left){
    leftChildPtr = left;
}

template<class T>
void BTreeNode<T>::setRightChildPtr(BTreeNode<T>* right){
    rightChildPtr = right;
}