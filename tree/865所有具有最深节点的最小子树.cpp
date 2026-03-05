#include "binarytree.h"
#include <iostream>
using namespace std;
class Solution {
public:
    TreeNode*ans;
    int maxdepth=0;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
    int dfs(TreeNode* root,int depth){
        if(root==nullptr){
            maxdepth=max(maxdepth,depth);
            return depth;
        }
        
        int left=dfs(root->left,depth+1);
        int right=dfs(root->right,depth+1);
        if(left==maxdepth&&right==maxdepth){
            ans=root;
        }
        return max(left,right);
    }
};