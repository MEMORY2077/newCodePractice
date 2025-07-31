#include "binarytree.h"
#include <iostream>
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        lastorder(root);
        return root;
    }
    void lastorder(TreeNode*root){
        if(root==nullptr)return;
        lastorder(root->left);
        lastorder(root->right);
        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
        return;
    }
};