#include "binarytree.h"
using namespace std;
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        t=k;
        return inorder(root);
    }
    int inorder(TreeNode *root){
        if(root==nullptr)return -1;
        int ans=inorder(root->left);
        if(ans!=-1)return ans;
        now++;
        if(now==t)return root->val;
        return inorder(root->right);
    }
    int t=0;
    int now=0;
};