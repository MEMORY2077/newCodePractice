#include "binarytree.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        inorder(root);
        inorder2(root);
        int n=fir.size();
        for(int i=0;i<n;i++){
            cout<<fir[i]<<' ';
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<sec[i]<<' ';
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            if(fir[i]!=sec[i])return false;
        }
        return true;
    }
    void inorder(TreeNode*root){
        if(root==nullptr){
            fir.push_back(-114514);
            return;
        }
        inorder(root->left);
        fir.push_back(root->val);
        inorder(root->right);
        return;
    }
    void inorder2(TreeNode*root){
        if(root==nullptr){
            sec.push_back(-114514);
            return;
        }
        inorder2(root->right);
        sec.push_back(root->val);
        inorder2(root->left);
        return;
    }
    vector<int>fir;
    vector<int>sec;
};
