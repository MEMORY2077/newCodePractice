#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            preorder(root);
            queue<TreeNode*>q;
            unordered_set<TreeNode*>visited;
            q.push(target);
            visited.emplace(target);
            int distance=0;
            vector<int>ans;
            while(!q.empty()){
                int sz=q.size();
                for(int _=0;_<sz;_++){
                    TreeNode*now=q.front();
                    q.pop();
                    if(distance==k){
                        ans.push_back(now->val);
                        continue;
                    }
                    if(now->left&&!visited.count(now->left)){
                    q.push(now->left);
                    visited.emplace(now->left);
                    }
                    if(now->right&&!visited.count(now->right)){
                    q.push(now->right);
                    visited.emplace(now->right);
                    }
                    if(parent.find(now->val)!=parent.end()&&!visited.count(parent[now->val])){
                    q.push(parent[now->val]);
                    visited.emplace(parent[now->val]);
                    }
                }
                distance++;
            }
            return ans;
        }
        void preorder(TreeNode*root){
            if(!root)return;
            if(root->left){
                parent[root->left->val]=root;
            }
            if(root->right){
                parent[root->right->val]=root;
            }
            preorder(root->left);
            preorder(root->right);
        }    
        unordered_map<int,TreeNode*>parent;
    };