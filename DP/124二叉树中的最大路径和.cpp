#include "binarytree.h"
#include <limits.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maximum;
    }
    int dfs(TreeNode*root){
        if(root==nullptr)return 0;
        int left=max(dfs(root->left),0);
        int right=max(dfs(root->right),0);
        maximum=max(maximum,left+right+root->val);//连接左右两条子链
        return max(0,max(left,right)+root->val);//从两条子链中选出最大的一条连接
    }
    int maximum=INT_MIN;
};