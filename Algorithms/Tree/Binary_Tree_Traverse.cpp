/*

Input Format

The first line contains an integer n, the number of nodes in the tree. 
Next line contains n space separated integer where ith integer denotes node[i].data.

Output Format

Your function should return a single integer denoting the height of the binary tree.

*/

//#include <bits/stdc++.h>
#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }


/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if(root){
            return 1+max(height(root->left), height(root->right));
        } else {
            return -1;
        }
    }

    void preOrderTraverse(Node* root){
        if(root){
            cout << root->data << " ";
            preOrderTraverse(root->left);
            preOrderTraverse(root->right);
        }

        return;

    }

    void inOrderTraverse(Node* root){
        if(root){
            inOrderTraverse(root->left);
            cout << root->data << " ";
            inOrderTraverse(root->right);
        }

        return;

    }

    void postOrderTraverse(Node* root){
        if(root){
            postOrderTraverse(root->left);
            postOrderTraverse(root->right);
            cout << root->data << " ";
        }

        return;
    }


}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;
    
    //7
    //3 5 2 1 4 6 7
    /*
            3
        2       5
    1       4       6
                        7
    */
    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    //std::cout << height;

    myTree.preOrderTraverse(root);
    cout << endl;
    myTree.inOrderTraverse(root);
    cout << endl;
    myTree.postOrderTraverse(root);
    count << endl;


    return 0;
}




