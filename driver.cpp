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
    int tree[100];
    int i, j, temp;
    bool added;

    cout << "=================================================" << endl;
    cout << "\t\tBINARY SEARCH TREE\t\t" << endl;
    cout << "Description: 100 randomly generated numbers, ranging from 1 to 200" << endl;
    cout << "=================================================" << endl << endl;

    for(i = 1; 1 <= 100; i++){
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
        cout << tree[i-1] << 't';

        if(i % 10 == 0){
            cout << "=================================================" << endl;
        }
    }
    
    cout << endl; 
    BST<int> main;

    for(i = 0; i < 100; i++){
        main.add(tree[i]);
    }
    
    cout << "Tree Height: " << main.getHeight() << endl << endl;
    cout << "Tree inorder: " << endl;
        main.inorderTraverse(traverse);
    cout << "Tree preorder: " << endl;
        main.preorderTraverse(traverse);
    cout << "Tree postorder: " << endl;
        main.postorderTraverse(traverse);
    cout << endl << endl;

    return 0;
}

template<class T>
void traverse(T& value){
    cout << value << ' ';
}