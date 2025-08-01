#include "binarytree.h"
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode*root=build(preorder,inorder);
        return root;
    }
    TreeNode*build(vector<int>preorder,vector<int>inorder){
        if(preorder.empty())return nullptr;
        int d=0;
        for(d;d<inorder.size();d++){
            if(inorder[d]==preorder[0])break;
        }
        vector<int>preorder1(preorder.begin()+1,preorder.begin()+d+1);
        vector<int>preorder2(preorder.begin()+d+1,preorder.end());
        vector<int>inorder1(inorder.begin(),inorder.begin()+d);
        vector<int>inorder2(inorder.begin()+d+1,inorder.end());
        TreeNode*root=new TreeNode(preorder[0],build(preorder1,inorder1),build(preorder2,inorder2));
        return root;
    }
};