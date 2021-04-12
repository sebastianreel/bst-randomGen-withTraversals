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
// File Description: Linked Implementation for the binary tree (header file)                            //                                                                                    
//------------------------------------------------------------------------------------------------------//

#ifndef linked_btree
#define linked_btree

#include "tree_interface.h"
#include "binary_tree_node.h"

template <class T>
class LinkedBTree : public TreeInterface<T> {
    private:
        LinkedBTreeNode<T>* rootPtr;
    protected:
        int getHeightHelper(LinkedBTreeNode<T>* subTreePtr) const;
        int getNumOfNodesHelper(LinkedBTreeNode<T>* subTreePtr) const;
        LinkedBTreeNode<T>* balanceAdd(LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* newNodePtr);
        LinkedBTreeNode<T>* moveValuesUpTree(LinkedBTreeNode<T>* subTreePtr);

        virtual LinkedBTreeNode<T>* findNode(LinkedBTreeNode<T>* treePtr, const T& target, bool& isSuccessful) const;

        LinkedBTreeNode<T>* copyTree(const LinkedBTreeNode<T>* oldTreeRootPtr) const;
        void destroyTree(LinkedBTreeNode<T>* subTreePtr);

        void preorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const;
        void inorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const;
        void postorder(void visit(T&), LinkedBTreeNode<T>& treePtr) const;
    public:
        LinkedBTree();

        bool isEmpty() const;
        int getHeight() const;
        int getNumOfNodes() const;
        T getRootData() const;
        bool add(const T& newData);
        bool remove(const T& data);
        void clear();

        T getEntry(const T& anEntry) const;
        bool contains(const T& anEntry) const;

        void preorderTraverse(void visit(T&)) const;
        void inorderTraverse(void visit(T&)) const;
        void postorderTraverse(void visit(T&)) const;

        ~LinkedBTree();
};
#include "binary_tree.cpp"
#endif