#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class tree {
public:
    TreeNode *root;
    tree(): root(NULL) { }

    TreeNode * createTree(vector<int> &vec) {
        if(vec.size()) {
            root = new TreeNode(vec[0]);
        }
        queue<TreeNode*> q;
        q.push(root);
        int nextItem = 1;

 
        while(!q.empty()) {
            int curSize = q.size();
            for(int i=0;i<curSize; i++) {
                TreeNode *root = q.front();
                q.pop();
                if(nextItem < vec.size()) {
                    if(vec[nextItem]) {
                        root->left = new TreeNode(vec[nextItem]);
                        q.push(root->left);
                    }
                    nextItem++;
                } else {
                    break;
                }
                if(nextItem < vec.size()) {
                    if(vec[nextItem]) {
                        root->right = new TreeNode(vec[nextItem]);
                        q.push(root->right);
                    }
                    nextItem++;
                } else {
                    break;
                }
            }
            if(nextItem >= vec.size())
                break;
        }

        return root;
    }
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        int valueAtNode = dia(root, maxLen);
        //cout <<"value: "<<valueAtNode<<" maxLen:"<<maxLen <<endl;
        return max(maxLen, valueAtNode);
    }
    
    int dia(TreeNode *root, int &maxLen) {
            
        if(root) {
            int localMax = 0;
            int l=0,r=0;
            bool someChild = false;
            
            if(root->left) {
                l = dia(root->left, maxLen);
                localMax=l+1;
                someChild = true;
            }
            if(root->right) {
                r = dia(root->right, maxLen);
                localMax+=r+1;   
                someChild = true;
            }
            if(localMax > maxLen) {
                maxLen = localMax;
            }
            return (max(l,r)) + (someChild?1:0);
            //cout <<"Val: "<<val<<" maxLen: "<<maxLen<<endl;
            //return val;
        }   
        return 0;
    }
    
};


int main() {
    tree t;

    // Only limitation -> 0 represent null
    vector<int> v= {1};

    //vector<int> v= {1,2,3,4,5};
    TreeNode *root = t.createTree(v);

    Solution sln;
    cout<<"Diameter of this tree: "<<sln.diameterOfBinaryTree(root) << endl;
    return 0;
}