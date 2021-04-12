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
        return (1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr())));
    }
}

template <class T>
int LinkedBTree<T>::getNumOfNodesHelper(LinkedBTreeNode<T>* subTreePtr) const{
    if(subTree == nullptr){
        return 0;
    } else {
        return (1 + getNumOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumOfNodesHelper(subTreePtr->getRightChildPtr()));
    }
}

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

template <class T>
LinkedBTreeNode<T>* LinkedBTree<T>::moveValuesUpTree(LinkedBTreeNode<T>* subTreePtr){
    LinkedBTreeNode<T>* temp;

    if(subTreePtr->isLeaf()){
        delete subTreePtr;
        subTreePtr = nullptr;
        return nullptr;
    } 
    else if(subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() == nullptr){
        temp = subTreePtr->getLeftChildPtr();
        delete subTreePtr;
        subTreePtr = nullptr;
        return temp;
    }
    else if(subTreePtr->getRightChildPtr() != nullptr && subTreePtr->getLeftChildPtr() == nullptr){
        temp = subTreePtr->getRightChildPtr();
        delete subTreePtr;
        subTreePtr = nullptr;
        return temp;
    } else {
        temp = subTreePtr->getLeftChildPtr();
        subTreePtr->setItem(temp->getItem());
        moveValuesUpTree(temp);
    }
    reutrn nullptr;
}

template <class T>
LinkedBTreeNode<T>* LinkedBTree<T>::findNode(LinkedBTreeNode<T>* treePtr, const T& target, bool& isSuccessful) const{
    if(treePtr != nullptr){
        if(treePtr->getItem() == target){
            isSuccessful = true;
            return treePtr;
        } else {
            findNode(treePtr->getLeftChildPtr(), target, isSuccessful);
            findNode(treePtr->getRightChildPtr(), target, isSuccessful);
        }
    }
}

template <class T>
LinkedBTreeNode<T>* LinkedBTree<T>::removeValue(LinkedBTreeNode<T>* subTreePtr, const T target, bool& isSuccessful){
    if(subTreePtr == nullptr){
        isSuccessful = false;
        return nullptr;
    }
    else if(subTreePtr->getItem(0 == target){
        subTreePtr = moveValuesUpTree(subTreePtr);
        isSuccessful = true;
        return subTreePtr;
    } else {
        LinkedBTreeNode<T>* temp1 = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        LinkedBTreeNode<T>* temp2 = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        if(temp1 != nullptr){
            return temp1;
        } else {
            return temp2;
        }
    }
}

template <class T>
LinkedBTreeNode<T>* LinkedBTree<T>::copyTree(const LinkedBTreeNode<T>* oldTreeRootPtr) const{
    LinkedBTreeNode<T>* newTree = nullptr;

    if(oldTreeRootPtr != nullptr){
        newTree = new LinkedBTreeNode<T>(oldTreeRootPtr->getItem());
        newTree->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        newTree->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
    }
    return newTree;
}

template <class T>
void LinkedBTree<T>::destroyTree(LinkedBTreeNode<T>* subTreePtr){
    if(subTreePtr != nullptr){
        destroyTree(subTreePtr->getLeftChildPtr());
    }
}

template <class T>
void LinkedBTree<T>::preorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        T item = treePtr->getItem();
        visit(item);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
}

template <class T>
void LinkedBTree<T>::inorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        inorder(visit, treePtr->getLeftChildPtr());
        T item = treePtr->getItem();
        visit(item);
        inorder(visit, treePtr->getRightChildPtr());
    }
}

template <class T>
void LinkedBTree<T>::postorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        postorde(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        T item = treePtr->getItem();
        visit(item);
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
    return (this->getHeightHelper(rootPtr));
}

template <class T>
int LinkedBTree<T>::getNumOfNodes() const{              // getting the number of different nodes
    return (this->getNumOfNodesHelper(rootPtr));
}

template <class T>
T LinkedBTree<T>::getRootData() const{                  // does something?    
    return (rootPtr->getItem());
}

template <class T>
void LinkedBTree<T>::setRootData(const T& newData){
    if(isEmpty()){
        rootPtr = LinkedBTreeNode<T>(newData);
    }
}

template <class T>
bool LinkedBTree<T>::add(const T& newData){             // add function using the balanceAdd to help
    LinkedBTreeNode<T>* newNodePtr = new LinkedBTreeNode<T>(newData);
    rootPtr = balanceAdd(rootPtr, newNodePtr);

    return true;
}

template <class T>
bool LinkedBTree<T>::remove(const T& data){
    bool success = false;
    rootPtr = removeValue(rootPtr, anEntry, success);
    return success;
}

template <class T>
void LinkedBTree<T>::clear(){
    this->destroyTree(rootPtr);
    rootPtr = nullptr;
}

template <class T>
T LinkedBTree<T>::getEntry(const T& anEntry) const{
    LinkedBTreeNode<T>* itemLock = findNode(rootPtr, anEntry);

    if(itemLock != nullptr){
        return itemLock->getItem();
    } else {
        cout << "No item." << endl;
    }
}

template <class T>
bool LinkedBTree<T>::contains(const T& anEntry) const{
    LinkedBTreeNode<T>* itemLock = findNode(rootPtr, anEntry);

    if(itemLock == nullptr){
        return false;
    } else {
        return true;
    }
}

template <class T>
void preorderTraverse(void visit(T&)){
    this->preorder(visit, rootPtr);
}

template <class T>
void inorderTraverse(void visit(T&)){
    this->inorder(visit, rootPtr);
}

template <class T>
void postorderTraverse(void visit(T&)){
    this->postorder(visit, rootPtr);
}