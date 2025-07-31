#include "binarytree.h"
#include <iostream>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return -1;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return max(l,r)+1;
    }
    int maximum=0;
};