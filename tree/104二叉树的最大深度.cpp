#include "binarytree.h"
#include <iostream>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        inorder(root,1);
        return maximum;
    }
    void inorder(TreeNode*root,int depth){
        if(root==nullptr)return;
        inorder(root->left,depth+1);
        maximum=max(maximum,depth);
        inorder(root->right,depth+1);
    }
    int maximum=0;
};