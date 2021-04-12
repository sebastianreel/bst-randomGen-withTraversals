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
// File Description: Inserting values into the BST, putting them into a text file, print height,        //
// inorder, preorder, and postorder                                                                     //
//------------------------------------------------------------------------------------------------------//

#include <iostream>
#include <ctime>
#include "binary_search_tree.h"

using namespace std;

template <class T>
void traverse(T& value);

int main(){
    srand(time(NULL));

    int treeValue[100];
    int x, i, temp;
    bool added;

    cout << endl << "100 digit rangning from 1 to 200" << endl << endl;
    for(x = 1; x <= 100; x++){
        added = false;
        while(!added){
            added = true;
            temp = 1 + (rand() % 200);

            for(i = 0; i < x - 1; i++){
                if(temp == treeValue[i]){
                    added = false;
                }
            }
        } 

        treeValue[x - 1] = temp;
        cout << treeValue[x - 1] << '\t';

        if(x % 10 == 0){
            cout << endl;
        }
    }

    cout << endl;

    LinkedBSearchTree<int> mainT;

    for(x = 0; x < 100; i++){
        mainT.add(treeValue[i]);
    }

    cout << "Tree Height = " << mainTree.getHeight() << endl << endl;
    
    cout << "Tree inrder: " << endl;
    mainTree.inorderTraverse(traverse);
}