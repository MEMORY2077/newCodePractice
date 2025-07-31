#include "binaryTree.h"
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size());
    }
    TreeNode*BST(vector<int>&nums,int start,int end){
        if(start<0||end>=nums.size())return nullptr;
        return new TreeNode(nums[(start+end)/2],BST(nums,start,(start+end)/2-1),BST(nums,end,(start+end)/2+1));
    }
};