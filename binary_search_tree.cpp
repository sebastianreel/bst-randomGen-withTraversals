//----------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                             //
// Project: 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                  //
// Due Date: April 11, 2021                                                         //
//----------------------------------------------------------------------------------//

#include "binary_search_tree.h"

template<class T>
BST<T>::BST(): rootPtr(nullptr) {}

template<class T>
BST<T>::BST(const T& rootItem): rootPtr(BTreeNode<T>(rootItem, nullptr, nullptr)) {}

template<class T>
BST<T>::BST(const BST<T>& tree){
    rootPtr = this->copytree(tree.rootPtr);
}

// end constructor list
// begin protected list

template<class T>
BTreeNode<T>* BST<T>::placeNode(BTreeNode<T>* subTreePtr, BTreeNode<T>* newNode){
    BTreeNode<T>* temp;
    
    if(subTreePtr == nullptr){
        return newNode;
    } else if(subTreePtr->getItem() > newNode->getItem()){
        temp = placeNode(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(temp);
    
    } else {
        temp = placeNode(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(temp);
    }
    return subTreePtr;
}

template<class T>
BTreeNode<T>* BST<T>::removeValue(BTreeNode<T>* subTreePtr, const T target, bool& isSuccessful){
    BTreeNode<T>* temp;

    if(subTreePtr == nullptr){
        isSuccessful = false;
        return subTreePtr;
    } else if(subTreePtr->getItem() == target){
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
        return subTreePtr;
    } else if(subTreePtr->getItem() > target){
        temp = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(temp);
        return subTreePtr;

    } else {
        temp = temoveValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(temp);
        return subTreePtr;
    }
}

template <class T>
BTreeNode<T>* BST<T>::removeNode(BTreeNode<T>* np){
    BTreeNode<T>* nodeConnect;

    if(np->isLeaf()){
        delete np;
        np = nullptr;
        return np;
    } else if(np->getLeftChildPtr() == nullptr){
        nodeConnect = np->getRightChildPtr();
        delete np;
        np = nullptr;
        return nodeConnect;
    } else if(np->getRightChildPtr() == nullptr){
        nodeConnect = np->getLeftChildPtr();
        delete np;
        np = nullptr;
        return nodeConnect;
    
    } else {
        BTreeNode<T>* temp;
        T newNode;
        temp = temoveLeftMostNode(np->getRightChildPtr(), newNode);
        np->setRightChildPtr(temp);
        np->setItem(newNode);
        return np;
    }
}

template<class T>
auto BST<T>::removeLeftMostNode(BTreeNode<T>* subTreePtr, T& inorderSuccessor){
    if(subTreePtr->getleftChildPtr() == nullptr){
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    } else {
        BTreeNode<T>* temp;
        temp = removeLeftMostNode(subTreePtr->getLeftChild(), inorderSuccessor);
        subTreePtr->setLeftChildPtr(temp);
        return subTreePtr;
    }
}

template<class T>
auto BST<T>::findNode(BTreeNode<T>* treePtr, const T& target) const{
    if(treePtr == nullptr){
        return nullptr;
    } else if(treePtr->getItem() == target){
        return treePtr;
    } else if(treePtr->getItem() > target){
        return findNode(treePtr->getLeftChildPtr(), target);

    } else {
        return findNode(treePtr->getRightChildPtr(), target);
    }
}

// end protected section
// begin the public function definitions

template<class T>
bool BST<T>::isEmpty() const{
    return (rootPtr == nullptr);
}

template<class T>
int BST<T>::getHeight() const{
    return (this->getHeightHelper(rootPtr));
}

template<class T>
int BST<T>::getNumOfNodes() const{
    return (this->getNumOfNodesHelper(rootPtr));
}

template<class T>
T BST<T>::getRootData() const{
    return (rootPtr->getItem());
}

template<class T>
void BST<T>::setRootData(const T& newData){
    if(isEmpty()){
        rootPtr = BTreeNode<T>(newData);
    }
}

template<class T>
bool BST<T>::add(const T& newEntry){
    BTreeNode<T>* temp = new BTreeNode<T>(newEntry);
    rootPtr = placeNode(rootPtr, temp);
    return true;
}

template<class T>
bool BST<T>::remove(const T& anEntry){
    bool success = false;
    rootPtr = removeValue(rootPtr, anEntry, success);
    return success;
}

template<class T>
void BST<T>::clear(){
    this->destroyTree(rootPtr);
    rootPtr = nullptr;
}

template<class T>
T BST<T>::getEntry(const T& anEntry) const{
    BTreeNode<T>* itemLock = findNode(rootPtr, anEntry);
    if(itemLock != nullptr){
        return itemLock->getItem();
    } else {
        std::cout << "No item." << std::endl;
    }
}

template<class T>
bool BST<T>::contains(const T& anEntry) const{
    BTreeNode<T>* itemLock = findNode(rootPtr, anEntry);
    if(itemLock == nullptr){
        return false;
    } else {
        return true;
    }
}

template<class T>
void BST<T>::preorderTraverse(void visit(T&)) const{
    this->preorder(visit, rootPtr);
}

template<class T>
void BST<T>::inorderTraverse(void visit(T&)) const{
    this->inorder(visit, rootPtr);
}

template<class T>
void BST<T>::postorderTraverse(void visit(T&)) const{
    this->postorder(visit, rootPtr);
}

template<class T>
BST<T>& BST<T>::operator = (const BST<T>& rightHandSide){
    if(!isEmpty()){
        clear();
    }
    rootPtr = this->copyTree(rightHandSide.rootPtr);
    return *this;
}