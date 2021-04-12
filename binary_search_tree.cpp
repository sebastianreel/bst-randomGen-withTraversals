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

#include "binary_search_tree.h"

// protected functions

template <class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::placeNode(LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* newNodePtr){
    LinkedBTreeNode<T>* temp;

    if(subTreePtr == nullptr){
        return newNodePtr;
    }
    else if(subTreePtr->getItem() > newNodePtr->getItem()){
        temp = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreeptr->setLeftChildPtr(temp);
    } else {
        temp = palceNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(temp);
    }

    return subTreePtr;
}

template <class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::removeValue(LinkedBTreeNode<T>* subTreePtr, const T target, bool& isSuccessul){
    LinkedBTreeNode<T>* temp;

    if(subTreePtr == nullptr){
        isSuccessful = false;
        reutrn subTreePtr;
    }
    else if(subnTreePtr->getItem() == target){
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = truel
        return subTreePtr;
    }
    else if(subTreePtr->getItem() > target){
        temp = temoveValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(temp);
        return subTreePtr;
    } else {
        temp = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(temp);
        return subTreePtr;
    }
}

template <class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::removeNode(LinkedBTreeNode<T>* nodePtr){
    BinaryNode<Type>* nodeConnect;

    if(nodePtr->isLeaf()){
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }
    else if(nodePtr->getLeftChildPtr() == nullptr){
        nodeConnect = nodePtr->getRightChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeConnect;
    }
    else if(nodePtr->getRightChildPtr() == nullptr){
        nodeConnect = nodePtr->getLeftChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeConnect;
    }
    else{
        BinaryNode<Type>* tmpPtr;
        T newNode;
        temp = removeLeftmostNode(newNodePtr->getRightChildPtr(), newNode);
        newNodePtr->setRightChildPtr(temp);
        newNodePtr->setItem(newNode);
        return newNodePtr;
    }
}

template <class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::removeLeftMostNode(LinkedBTreeNode<T>* subTreePtr, T& inOrderSuccessor){
    if(subTreePtr->getLeftChildPtr() == nullptr){
        inOrderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    } else {
        LinkedBTreeNode<T>* temp;
        temp = removeLeftMostNode(subTreePtr->getLeftChildPtr(), inOrderSuccessor);
        subTreePtr->setLeftChildPtr(temp);
        return subTreePtr;
    }
}

template <class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::findNode(LinkedBTreeNode<T>* treePtr, const T& target) const{
    if(treePtr == nullptr){
        reutrn nullptr;
    }
    else if(treePtr->getItem() == target){
        return treePtr;
    }
    else if(treePtr->getItem() > target){
        return findNode(treePtr->getLeftChildPtr(), target);
    } else {
        return findNode(treePtr->getRightChildPtr(), target);
    }
}

//public functions

template <class T>
LinkedBSearchTree<T>::LinkedBSearchTree() : rootPtr(nullptr){}

template <class T>
bool LinkedBSearchTree<T>::isEmpty() const{
    return (rootPtr == nullptr);
}

template <class T>
int LinkedBSearchTree<T>::getHeight() const{
    return (this->getHeightHelper(rootPtr));
}

template <class T>
int LinkedBSearchTree<T>::getNumOfNodes() const{
    return (this->getNumOfNodesHelper(rootPtr));
}

template <class T>
T LinkedBSearchTree<T>::getRootData() const{
    return (rotPtr->getItem());
}

template <class T>
void LinkedBSearchTree<T>::setRootData(const T& newData){
    is(isEmpty()){
        rootPtr = LinkedBTreeNode<T>(newData);
    }
}

template <class T>
bool LinkedBSearchTree<T>::add(const T& newEntry){
    LinkedBTreeNode<T>* temp = new LinkedBTreeNode<T>(newEntry);

    rootPtr = palceNode(rootPtr, temp);
    return true;
}

template <class T>
bool LinkedBSearchTree<T>::remove(const T& anEntry){
    bool success = false;
    rootPtr = removeValue(rootPtr, anEntry, success);
    return success;
}

template <class T>
void LinkedBSearchTree<T>::clear(){
    this->destroyTree(rootPtr);
    rootPtr = nullptr;
}

template <class T>
T LinkedBSearchTree<T>::getEntry(const T& anEntry) const{
    LinkedBTreeNode<T>* itemLock = findNode(rootPtr, anEntry);

    if(itemLock != nullptr){
        reutrn itemLock->getItem();
    } else {
        cout << "No item." << endl;
    }
}

template <class T>
bool LinkedBSearchTree<T>::contains(const T& anEntry) const{
    LinkedBTreeNode<T>* itemLock = findNode(root, anEntry);

    if(itemLock == nullptr){
        return false;
    } else {
        return true;
    }
}

template <class T>
void LinkedBSearchTree<T>::preorderTraverse(void visit(T&)) const{
    this->preorder(visit, rootPtr);
}

template <class T>
void LinkedBSearchTree<T>::inorderTraverse(void visit(T&)) const{
    this->preorder(visit, rootPtr);
}

template <class T>
void LinkedBSearchTree<T>::postorderTraverse(void visit(T&)) const{
    this->postorder(visit, rootPtr);
}

template <class T>
LinkedBSearchTree<T>& LinkedBSearchTree<T>::operator = (const LinkedBSearchTree<T>& rightHandSide){
    if(!isEmpty()){
        clear();
    }
    rootPtr = this->copyTree(rightHandSide.rootPtr);

    return *this;
}