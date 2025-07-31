#include "binarytree.h"
#include <iostream>
using namespace std;
class Solution {
long long pre=LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        if(!isValidBST(root->left))return false;
        if(root->val<=pre)return false;
        pre=root->val;
        return (isValidBST(root->right));
    }
};