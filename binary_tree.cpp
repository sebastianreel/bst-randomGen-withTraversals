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
// File Description: Function Definitions for the header file for the Binary Tree                       //                                                                                  
//------------------------------------------------------------------------------------------------------//

#include "binary_tree.h"

//protected function definitions

template <class T>
int LinkedBTree<T>::getHeightHelper(LinkedBTreeNode<T>* subTreePtr) const{              // This function is helping the getHeight function be able to find the height of the tree
    if(subTreePtr == nullptr){
        return 0;
    } else {
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

// template <class T>


template <class T>
LinkedBTreeNode<T>* LinkedBTree<T>::balanceAdd(LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* newNodePtr){     //balanceAdd aids the add function in working out adding a node to the tree
    if(subTreePtr == nullptr){
        return newNodePtr;
    } else {
        LinkedBTreeNode<T>* leftPtr = subTreePtr->getLeftChildPtr();
        LinkedBTreeNode<T>* rightPtr = subTreePtr->getRightChildPtr();

        if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr)){
            rightPtr = balanceAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        } else {
            leftPtr = balanceAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        }

        return subTreePtr;
    }
}

// public function definitions

template <class T>
LinkedBTree<T>::LinkedBTree() : rootPtr(nullptr);       // constructor

template <class T>
bool LinkedBTree<T>::isEmpty() const{                   // Checking if it is empty
    return rootPtr == nullptr;
}

template <class T>
int LinkedBTree<T>::getHeight() const{                  // height of tree?
    return getHeightHelper(rootPtr);
}

template <class T>
int LinkedBTree<T>::getNumOfNodes() const{              // getting the number of different nodes

}

template <class T>
T LinkedBTree<T>::getRootData() const{                  // does something?    

}

template <class T>
bool LinkedBTree<T>::add(const T& newData){             // add function using the balanceAdd to help
    LinkedBTreeNode<T>* newNodePtr = new LinkedBTreeNode<T>(newData);
    rootPtr = balanceAdd(rootPtr, newNodePtr);

    return true;
}

template <class T>
bool LinkedBTree<T>::remove(const T& data){

}

template <class T>
void LinkedBTree<T>::clear(){

}

template <class T>
T LinkedBTree<T>::getEntry(const T& anEntry) const{

}

template <class T>
bool LinkedBTree<T>::contains(const T& anEntry) const{

}

template <class T>
void preorderTraverse(void visit(T&)){

}

template <class T>
void inorderTraverse(void visit(T&)){

}

template <class T>
void postorderTraverse(void visit(T&)){

}