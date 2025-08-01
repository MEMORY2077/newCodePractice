#include "binarytree.h"

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        t=targetSum;
        preorder(root);
        return ans;
    }
    int ans=0;
    void bfs(TreeNode*root,long long k){
        if(root==nullptr)return;
        k-=root->val;
        if(k==0){
            ans++;
            //return;
        }
        //if(k<0)return;
        bfs(root->left,k);
        bfs(root->right,k);
        return;
    }
    void preorder(TreeNode*root){
        if(!root)return;
        bfs(root,t);
        preorder(root->left);
        preorder(root->right);
    }
    int t=0;
};