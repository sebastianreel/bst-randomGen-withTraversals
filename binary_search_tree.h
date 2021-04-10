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
// File Description: The binary search tree header file with function prototypes, inherits the          //
// binary tree and tree node                                                                            //                                                                                    
//------------------------------------------------------------------------------------------------------//

#ifndef linked_bst
#define linked_bst

#include "binary_tree_node.h"
#include "binary_tree.h"

template <class T>
class LinkedBSearchTree : public LinkedBTree<T> {
    private:
        LinkwedBTreeNode<T>* rootPtr;
    protected:
        LinkedBTreeNode<T>* placeNode(LinkedBTreeNode<T> subTreePtr, LinkedBTreeNode<T>* newNodePtr);
        LinkedBTreeNode<T>* removeValue(LinkedBTreeNode<T> subTreePtr, const T target, bool& isSuccessful) override;
        LinkedBTreeNode<T>* removeNode(LinkedBTreeNodeQ<T>* nodePtr);
        LinkedBTreeNode<T>* removeLeftMostNode(LinkedBTreeNode<T>* inorderSuccessor);
        LinkedBTreeNode<T>* findNode(LinkedBTreeNode<T>* treePointer, const T& target) const;
    public:
        LinkedBSearchTree();

        bool isEmpty() const;
        int getHeight() const;
        int getNumOfNodes() const;
        T getRootData() cosnt;
        bool add(const T& data);
        void clear();
        T getEntry(const T& anEntry) const;
        bool contains(const T& anEntry); const;

        void preorderTraverse(void visit(T&)) const;
        void inorderTraverse(void visit(T&)) const;
        void postordrerTraverse(void visit(T&)) const;

        ~LinkedBSearchTree();
};
#include "binary_search_tree.cpp"
#endif