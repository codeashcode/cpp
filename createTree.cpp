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

int main() {
    tree t;

    // Only limitation -> 0 represent null
    vector<int> v= {3,9,8,4,1,2,7,0,0,0,2,5};
    TreeNode *root = t.createTree(v);
    inOrder(root);
}
