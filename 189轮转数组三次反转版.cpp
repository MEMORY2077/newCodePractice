//参考题解：https://leetcode.cn/problems/rotate-array/solutions/2784427/tu-jie-yuan-di-zuo-fa-yi-tu-miao-dong-py-ryfv/?envType=study-plan-v2&envId=top-100-liked
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverse(vector<int>&nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        return;
    }
};