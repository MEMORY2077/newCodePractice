#include "binarytree.h"
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)return;
        flatten(root->right);
        flatten(root->left);
        root->right=head;
        root->left=nullptr;
        head=root;
    }
    TreeNode*head;
};