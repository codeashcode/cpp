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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        auto newRes = traverse(root);
        
        cout << "Result:" <<endl;
        cout << "[" <<endl;
        for(vector<int> one: newRes) {
            cout <<"  [";
            for(int num: one) {
                cout << " "<<num;
            }
            cout <<"]";
            cout <<endl;
        }
        cout << endl << "]";
    
        cout <<endl;
        
        return newRes;
        
    }
    
    vector<vector<int>> traverse(TreeNode *root) {

        int width = 0;

        vector<vector<int>> res;
        map<int, vector<int>> res_partial;

        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>{root, width});

        while(!q.empty()) {
            int curSize = q.size();
            for(int i=0;i<curSize; i++) {
                auto head = q.front();
                q.pop();
                res_partial[head.second].push_back(head.first->val);
                if(head.first->left) {
                    q.push(pair<TreeNode*, int> {head.first->left, head.second-1});    
                }
                if(head.first->right) {
                    q.push(pair<TreeNode*, int> {head.first->right, head.second+1});    
                }
            }
        }    

        int minColumn = abs(res_partial.begin()->first);

        for(auto itr=res_partial.begin(); itr!=res_partial.end(); itr++) {
            res.push_back(itr->second);
        }
        return res;
    }
};

void inOrder(TreeNode *root) {
    if(root) {
        inOrder(root->left);
        cout <<" "<<root->val;
        inOrder(root->right);
    }
}

int main() {
    Solution sln;
    tree t;
    vector<int> v= {3,9,8,4,1,2,7,0,0,0,2,5};
    TreeNode *root = t.createTree(v);
    inOrder(root);
    sln.verticalOrder(root);
}