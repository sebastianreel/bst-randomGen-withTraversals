//----------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                             //
// Project: 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                  //
// Due Date: April 11, 2021                                                         //
//----------------------------------------------------------------------------------//

#include "binary_tree.h"

template<class T>
BinaryTree<T>::BinaryTree(): rootPtr(nullptr) {}

template<class T>
BinaryTree<T>::BinaryTree(T& rootItem): rootPtr(BTreeNode<T>(rootItem, nullptr, nullptr)) {}

template<class T>
BinaryTree<T>::BinaryTree(const T& root, const BTreeNode<T>* leftTreePtr, const BTreeNode<T>* rightTreePtr): rootPtr(BTreeNode<T>(root, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr))) {}

template<class T>
BinaryTree<T>::BinaryTree(const BTreeNode<T>& tree){
    rootPtr = copyTree(tree.rootPtr);
}

// end constructors
// start protected functions

template<class T>
int BinaryTree<T>::getHeightHelper(BTreeNode<T>* subTreePtr) const{
    if(subTreePtr == nullptr){
        return 0;
    } else {
        return (1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr())));
    }
}

template<class T>
int BinaryTree<T>::getNumOfNodesHelper(BTreeNode<T>* subTreePtr) const{
    if(subTreePtr == nullptr){
        return 0;
    } else {
        reutnr (1 + getNumOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumOfNodesHelper(subTreePtr->getRightChildPtr()));
    }
}

template<class T>
auto BinaryTree<T>::balanceAdd(BTreeNode<T>* subTreePtr, BTreeNode<T>* newNodePtr){
    if(subTreePtr == nullptr){
        return newNodePtr;
    } else {
        auto leftPtr = subTreePtr->getLeftChildPtr();
        auto rightPtr = subTreePtr->getRightChildPtr();
        
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

template<class T>
BTreeNode<T>* BinaryTree<T>::moveValuesUpTree(BTreeNode<T>* subTreePtr){
    BTreeNode<T>* temp;

    if(subTreePtr->isLeaf()){
        delete subTreePtr;
        subTreePtr = nullptr;
        return nullptr;
    } else if(subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() == nullptr){
        temp = subTreePtr->getLeftChild();
        delete subTreePtr;
        subTreePtr = nullptr;
        return temp;
    } else if(subTreePtr->getRightChildPtr() != nullptr && subTreePtr->getLeftChildPtr() == nullptr){
        temp = subTreePtr->getRightChildPtr();
        delete subTreePtr;
        subTreePtr = nullptr;
        return temp;
    } else {
        temp = subTreePtr->getLeftChildPtr();
        subTreePtr->setItem(temp->getItem());
        moveValuesUpTree(temp);
    }
    return nullptr;
}

template<class T>
auto BinaryTree<T>::copyTree(BTreeNode<T>* oldTreeRootPtr) const{
    BTreeNode<T>* newTree = nullptr;

    if(oldTreeRootPtr != nullptr){
        newTree = new BTreeNode<T>(oldTreeRootPtr->getItem());
        newTree->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        newTree->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
    }
    return newTree;
}

template<class T>
void BinaryTree<T>::destroyTree(BTreeNode<T>* subTreePtr){
    if(subTreePtr != nullptr){
        destroyTree(subTreePtr->getLeftChildPtr());
    }
}

template<class T>
BTreeNode<T>* BinaryTree<T>::findNode(BTreeNode<T>* treePtr, const T& target, bool& isSuccessful) const{
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

template<class T>
BTreeNode<T>* BinaryTree<T>::removeValue(BTreeNode<T>* subTreePtr, const T target, bool& isSuccessful){
    if(subTreePtr == nullptr){
        isSuccessful = false;
        return nullptr;
    } else if(subTreePtr->getItem() == target){
        subTreePtr = movesValuesUpTree(subTreePtr);
        isSuccessful = true;
        return subTreePtr;
    
    } else {
        BTreeNode<T>* t1 = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        BTreeNode<T>* t2 = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        if(t1 != nullptr){
            return t1;
        } else {
            return t2;
        }
    }
}

template<class T>
void BinaryTree<T>::preorder(void visit(T&), BTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        T item = treePtr->getItem();
        visit(item);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
}

template<class T>
void BinaryTree<T>::inorder(void visit(T&), BTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        inorder(visit, treePtr->getLeftChildPtr());
        T item = treePtr->getItem();
        visit(item);
        inorder(visit, treePtr->getRightChildPtr());
    }
}

template<class T>
void BinaryTree<T>::postorder(void visit(T&), BTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        T item = treePtr->getItem();
        visit(item);
    }
}

// end protected
// im not implementing the public, since they arent used 
// if that changes, i will implement them into the source file 

template<class T>
bool BinaryTree<T>::isEmpty() const{
    return (rootPtr == nullptr);
}