//----------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                             //
// Project: 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                  //
// Due Date: April 11, 2021                                                         //
//----------------------------------------------------------------------------------//

#ifndef binary_tree
#define binary_tree
#include "tree_interface.h"
#include "binary_tree_node.h"

template<class T>
class BinaryTree{
    BTreeNode<T>* rootPtr;
protected:
    int getHeightHelper(BTreeNode<T>* subTreePtr) const;
    int getNumOfNodesHelper(BTreeNode<T>* subTreePtr) const;
    auto balanceAdd(BTreeNode<T>* subTreePtr, BTreeNode<T>* newNodePtr);
    BTreeNode<T>* moveValuesUpTree(BTreeNode<T>* subTreePtr);
    auto copyTree(BTreeNode<T>* oldTreeRootPtr) const;
    void destroyTree(BTreeNode<T>* subTreePtr);

    virtual BTreeNode<T>* findNode(BTreeNode<T>* treePtr, const T& target, bool& isSuccessful) const;
    virtual BTreeNode<T>* removeValue(BTreeNode<T>* subTreePtr, const T target, bool& isSuccessful);

    void preorder(void visit(T&), BTreeNode<T>* treePtr) const;
    void inorder(void visit(T&), BTreeNode<T>* treePtr) const;
    void postorder(void visit(T&), BTreeNode<T>* treePtr) const;
public:
    //default constructor
    BinaryTree();
    //parameterized constructor
    BinaryTree(T& rootItem);
    BinaryTree(const T& root, const BTreeNode<T>* leftTreePtr, const BTreeNode<T>* rightTreePtr);
    //copy constructor
    BinaryTree(const BTreeNode<T>& tree);

    bool isEmpty() const;
    int getHeight() const;
    int getNumOfNodes() const;
    T getRootData() const;
    bool add(const T& newEntry);
    bool remove(const T& anEntry);
    void clear();
    T getEntry(const T& anEtry) const;
    bool contains(const T& anEntry) const;

    void preorderTraverse(void visit(T&)) const;
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T&)) const;

    // try deleting this later and see if it changes anything
    // this might not be used and would look better without
    BinaryTree& operator = (const BinaryTree& rightHandSide);
};
#include "binary_tree.cpp"
#endif