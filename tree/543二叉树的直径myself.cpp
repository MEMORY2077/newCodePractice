#include "binaryTree.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        inorder(root);
        return maximum;
    }
    void inorder(TreeNode*root){
        if(root==nullptr)return;
        inorder(root->left);
        int D=0;
        int ld=0;
        int rd=0;
        inorder2(root->left,1,ld);
        inorder2(root->right,1,rd);
        //if(ld!=0)ld++;
        //if(rd!=0)rd++;
        D=ld+rd;
        maximum=max(maximum,D);
        inorder(root->right);
    }
    void inorder2(TreeNode*root,int depth,int &maxi){
        if(root==nullptr)return;
        if(depth>maxi)maxi=depth;
        inorder2(root->left,depth+1,maxi);
        inorder2(root->right,depth+1,maxi);
    }
    int maximum=INT_MIN;
};