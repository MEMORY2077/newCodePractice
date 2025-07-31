#include "binarytree.h"
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*now=q.front();
                q.pop();
                if(now->left)q.push(now->left);
                if(now->right)q.push(now->right);
                if(i==size-1)ans.push_back(now->val);
            }
        }
        return ans;
    }
};