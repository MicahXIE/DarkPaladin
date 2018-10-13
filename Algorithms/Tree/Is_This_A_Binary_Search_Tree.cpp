/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}

testing case:
2
1 2 4 3 5 6 7
*/

	bool checkBST(Node* root) {
        vector<int> vc;
        inOrderTraverse(root, &vc);
        
        for(int i=1; i<vc.size(); i++){
            //cout << vc[i] << endl;
            if(vc[i] > vc[i-1]){
                continue;
            }else{
                return false;
            }
        }
		
        return true;
	}

    void inOrderTraverse(Node* root, vector<int> *v){
        if(root == NULL) return;
        
        inOrderTraverse(root->left, v);
        (*v).push_back(root->data);
        inOrderTraverse(root->right, v);
        
    }


