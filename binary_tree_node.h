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
// File Description: Linked Based Implementation header file for the Binary Tree Node                   //                                                                                  
//------------------------------------------------------------------------------------------------------//

#ifndef linked_btree_node
#define linked_btree_node

template <class T>
class LinkedBTreeNode {
    T item;
    Node<T>* leftChildPtr;
    Node<T>* rightChildPtr;
public:
    LinkedBTreeNode();
    LinkedBTreeNode(const T& newData, LinkedBTreeNode<T>* left, LinkedBTreeNode<T>* right);

    void setItem(const T& newData);
    T getItem() const;

    bool isLeaf() const;

    LinkedBTreeNode<T>* getLeftChildPtr() const;
    LinkedBTreeNode<T>* getRightChildPtr() const;

    void setLeftChildPtr(LinkedBTreeNode<T>* newLeftChildPtr);
    void setRightChildPtr(LinkedBTreeNode<T>* newRightChildPtr);
};
#include "binary_tree_node.cpp"
#endif