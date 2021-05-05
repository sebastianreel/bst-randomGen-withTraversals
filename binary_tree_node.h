//----------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                             //
// Project: 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                  //
// Due Date: April 11, 2021                                                         //
//----------------------------------------------------------------------------------//

#ifndef binary_tree_node
#define binary_tree_node

template<class T>
class BTreeNode{
    T item;
    BTreeNode<T>* leftChildPtr;
    BTreeNode<T>* rightChildPtr;
public:
    BTreeNode();
    BTreeNode(const T& anItem);
    BTreeNode(const T& anItem, BTreeNode<T>* left, BTreeNode<T>* right);

    void setItem(const T& anItem);
    T getItem() const;
    bool isLeaf() const;
    BTreeNode<T>* getLeftChildPtr() const;
    BTreeNode<T>* getRightChildPtr() const;
    void setLeftChildPtr(BTreeNode<T>* left);
    void setRightChildPtr(BTreeNode<T>* right);
};
#include "binary_tree_node.cpp"
#endif