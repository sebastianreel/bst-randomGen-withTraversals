//----------------------------------------------------------------------------------//
// Name: Sebastian Reel                                                             //
// Project: 5 - Binary Search Tree and In Order, Preorder, and Post Order Traversal //
//                                                                                  //
// Due Date: April 11, 2021                                                         //
//----------------------------------------------------------------------------------//

#include "binary_search_tree.h"  
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

template<class T>
void traverse(T& x);

int main(){
    srand(time(NULL));
    ofstream fp;
    int tree[100];
    int i, j, temp;
    bool added;
    
    fp.open("print.txt");
    cout << "||======================================================================||" << endl;
    cout << "||\t\t\t   BINARY SEARCH TREE\t\t\t        ||" << endl;
    cout << "|| Description: 100 randomly generated numbers, ranging from 1 to 200   ||" << endl;
    cout << "||======================================================================||" << endl << endl;
    cout << "============================================================================" << endl;

    // printing into a file
    // different format than terminal
    fp << "||======================================================================||\n";
    fp << "||\t\t\t\t\t\t   BINARY SEARCH TREE\t\t\t\t\t        ||" << endl;
    fp << "|| Description: 100 randomly generated numbers, ranging from 1 to 200   ||" << endl;
    fp << "||======================================================================||" << endl << endl;
    fp << "============================================================================" << endl;

    for(i = 1; i <= 100; i++){
        added = false;
        while(!added){
            added = true;
            temp = 1 + (rand() % 200);

            for(j = 0; j < i - 1; j++){
                if(temp == tree[j]){
                    added = false;
                }
            }
        }

        tree[i-1] = temp;
        cout << tree[i-1] << "\t";
        fp << tree[i-1] << "\t\t";            // printing the tree into the file

        if(i % 10 == 0){
            cout << endl << "============================================================================" << endl;
            fp << endl << "============================================================================" << endl;       // printing tree seperator into the file
        }
    }
    cout << endl;
    fp << endl;         // tree done in file
    
    BST<int> main;
    for(i = 0; i < 100; i++){
        main.add(tree[i]);
    }
    
    cout << "Tree Height: " << main.getHeight() << endl << endl;
    cout << "Tree inorder: " << endl;
        main.inorderTraverse(traverse);
    fp << "Tree Height: " << main.getHeight() << endl << endl;
    fp << "Tree inorder: " << endl;
        // something with the inorder traversal here 
    cout << endl << endl << "Tree preorder: " << endl;
        main.preorderTraverse(traverse);
    fp << endl << endl << "Tree preorder: " << endl;
        // something with the preorder traversal here   
    cout << endl << endl << "Tree postorder: " << endl;
        main.postorderTraverse(traverse);
    fp << endl << endl << "Tree postorder: " << endl;
        // something with the post order here
    cout << endl << endl;
    fp << endl << endl;
    
    fp.close();
    return 0;
}

template<class T>
void traverse(T& x){
    // ofstream fp;
    // fp.open("print.txt");
    cout << x << ' ';

    // fp << x;
}