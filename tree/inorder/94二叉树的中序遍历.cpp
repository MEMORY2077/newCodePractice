#include "binarytree.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode*root){
        if(root==nullptr)return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return;
    }
    vector<int>ans;
};