#include <bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
    public:
        void dfs(TreeNode* root){
            if(root==nullptr)return;
            dfs(root->left);
            dfs(root->right);
            f[root]=root->val+g[root->left]+g[root->right];
            g[root]=max(g[root->left],f[root->left])+max(g[root->right],f[root->right]);
            return;
        }
        unordered_map<TreeNode*,int>g;
        unordered_map<TreeNode*,int>f;
        int rob(TreeNode* root) {
            dfs(root);
            return max(f[root],g[root]);
        }
    };