/*

You are given pointer to the root of the binary search tree and two values v1 and v2. 
You need to return the lowest common ancestor (LCA) of v1 and v2 in the binary search tree.

Sample Input

6
4 2 3 1 7 6
1 7

Sample Output

[reference to node 4]

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
  
    Node *lca(Node *root, int v1,int v2) {

        
        if(root == NULL)
            return root;
        
		// Write your code here.
        if(root->data < v1 && root->data < v2){
            root = lca(root->right, v1, v2);
        }
        
        if(root->data > v1 && root->data > v2){
            root = lca(root->left, v1, v2);
        }

        /*
			root	(root->data) vs (v1 v2)	
			1		1==1 return 1	(1,2)
			4 -> 1	return 1	
			8 -> 1  return 1

        */

    	cout << root->data << "->";
        
        return root;
        
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    cout << endl;
  	std::cout << ans->data << endl;

    return 0;
}
