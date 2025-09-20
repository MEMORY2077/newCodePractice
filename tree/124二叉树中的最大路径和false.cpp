#include "binarytree.h"
#include <limits.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        preorder(root);
        return maximum;
    }
    void preorder(TreeNode*root){
        if(!root)return;
        dfs(root,0);
        preorder(root->left);
        preorder(root->right);
    }
    void dfs(TreeNode* root,int now){
        if(root==nullptr)return;
        now+=root->val;
        maximum=max(maximum,now);
        dfs(root->left,now);
        dfs(root->right,now);
        return ;
    }
    int maximum=INT_MIN;
};