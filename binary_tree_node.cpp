//------------------------------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                                                 //
// Project: Homework Assignment 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                                      //
// Description: Randomly generate 100 unique values in the range of [1-200] and insert them into a      //
// binary search tree (BST). Print height and inorder, preorder, and postoder output of the BST tree.   //
// Deliver source code and a test file that shows the result of printing height and inorder, preorder,  //
// and postorder traversal.                                                                             // 
//                                                                                                      //
// Due Date: April 11, 2021                                                                             //
// File Description:                                                                                    //
//------------------------------------------------------------------------------------------------------//

#include "binary_tree_node.h"

template <class T>
LinkedBTreeNode<T>::LinkedBTreeNode() {
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

template <class T>
LinkedBTreeNode<T>::LinkedBTreeNode(const T& newData, LinkedBTreeNode<T>* left, LinkedBTreeNode<T>* right){
    item = newData;
    leftChildPtr = left;
    rightChildPtr = right;
}

template <class T>
void LinkedBTreeNode<T>::setItem(const T& newData){
    item = newData;
}

template <class T>
T LinkedBTreeNode<T>::getItem() const{
    return item;
}

template <class T>
bool LinkedBTreeNode<T>::isLeaf() const{
    if(leftChildPtr == nullptr && rightChildPtr == nullptr){
        return true;
    } else {
        return false;
    }
}

template <class T>
LinkedBTreeNode<T>* LinkedBTreeNode<T>::getLeftChildPtr() const{
    return leftChildPtr;
}

template <class T>
LinkedBTreeNode<T>* LinkedBTreeNode<T>::getRightChildPtr() const{
    return rightChildPtr;
}

template <class T>
void LinkedBTreeNode<T>::setLeftChildPtr(LinkedBTreeNode<T>* newLeftChildPtr){
    leftChildPtr = newLeftChildPtr;
}

template <class T>
void LinkedBTreeNode<T>::setRightChildPtr(LinkedBTreeNode<T>* newRightChildPtr){
    rightChildPtr = newRightChildPtr;
}