//----------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                             //
// Project: 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                  //
// Due Date: April 11, 2021                                                         //
//----------------------------------------------------------------------------------//

#ifndef binary_search_tree
#define binary_search_tree
#include "binary_tree_node.h"
#include "binary_tree.h"
#include <fstream>

template<class T>
class BST: public BinaryTree<T>{
    BTreeNode<T>* rootPtr;
protected:
    BTreeNode<T>* placeNode(BTreeNode<T>* subTreePtr, BTreeNode<T>* newNode);
    BTreeNode<T>* removeValue(BTreeNode<T>* subTreePtr, const T target, bool& isSuccessful);
    BTreeNode<T>*removeNode(BTreeNode<T>* np);
    auto removeLeftMostNode(BTreeNode<T>* subTreePtr, T& inorderSuccessor);
    auto findNode(BTreeNode<T>* treePtr, const T& target) const;
public:
    BST();
    BST(const T& rootItem);
    BST(const BST<T>& tree);

    bool isEmpty() const;
    int getHeight() const;
    int getNumOfNodes() const;
    T getRootData() const;
    void setRootData(const T& newData);
    bool add(const T& newEntry);
    bool remove(const T& anEntry);
    void clear();
    T getEntry(const T& anEtry) const;
    bool contains(const T& anEntry) const;

    void preorderTraverse(void visit(T&)) const;
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T&)) const;

    BST<T>& operator = (const BST<T>& rightHandSide);
};
#include "binary_search_tree.cpp"
#endif