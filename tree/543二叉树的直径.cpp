#include "binaryTree.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maximum;
    }
    int dfs(TreeNode*root){
        if(root==nullptr)return -1;
        int l=dfs(root->left);
        int r=dfs(root->right);
        maximum=max(maximum,l+r+2);
        return max(l,r)+1;
    }
    
    int maximum=INT_MIN;
};