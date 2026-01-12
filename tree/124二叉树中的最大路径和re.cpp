#include <binarytree.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution {
    public:
        int lastorder(TreeNode*root){
            if(!root)return 0;
            int l=max(lastorder(root->left),0);
            int r=max(lastorder(root->right),0);
            maximum=max(maximum,l+r+root->val);
            return max(0,max(l,r)+root->val);
        }
        int maxPathSum(TreeNode* root) {
            lastorder(root);
            return maximum;
        }
        int maximum=INT_MIN;
    };