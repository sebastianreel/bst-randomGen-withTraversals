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
// File Description: The Tree Interface that will be inherited in other Tree files                      //
//------------------------------------------------------------------------------------------------------//

#ifndef tree_interface;
#define tree_interface;

template <class T>
class TreeInterface {
    public:
        virtual bool isEmpty() const = 0;
        virtual int getHeight() const = 0;
        virtual int getNumOfNodes() const = 0;
        virtual T getRootData() const = 0;
        virtual bool add(const T& newEntry) = 0;
        virtual bool remove(const T& anEntry) = 0;
        virtual void clear() = 0;
        virtual T getEntry(const T& anEtry) const = 0;
        virtual bool contains(const T& anEntry) const = 0;

        virtual ~TreeInterface() { }
};
#endif