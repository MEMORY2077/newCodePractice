#include "binarytree.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return check(root->left,root->right);
    }
    bool check(TreeNode*p,TreeNode*q){
        if(!p&&!q)return true;
        if(!p||!q)return false;
        return p->val==q->val&&check(p->left,q->right)&&check(p->right,q->left);
    }
};
