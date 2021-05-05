//----------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                             //
// Project: 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                  //
// Due Date: April 11, 2021                                                         //
//----------------------------------------------------------------------------------//

#ifndef tree_interface
#define tree_interface

template <class T>
class TreeInterface {
    public:
        virtual bool isEmpty() const = 0;
        virtual int getHeight() const = 0;
        virtual int getNumOfNodes() const = 0;
        virtual T getRootData() const = 0;
        virtual void setRootData(const T& newData) = 0;
        virtual bool add(const T& newEntry) = 0;
        virtual bool remove(const T& anEntry) = 0;
        virtual void clear() = 0;
        virtual T getEntry(const T& anEtry) const = 0;
        virtual bool contains(const T& anEntry) const = 0;

        virtual void preorderTraverse(void visit(T&)) const = 0;
        virtual void inorderTraverse(void visit(T&)) const = 0;
        virtual void postorderTraverse(void visit(T&)) const = 0;
};
#endif