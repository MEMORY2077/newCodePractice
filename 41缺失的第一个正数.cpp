#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int now=0;
        while(now<n){
            if(nums[now]>n||nums[now]<=0||nums[nums[now]-1]==nums[now]){
                now++;
                continue;
            }
            int temp=nums[nums[now]-1];
            nums[nums[now]-1]=nums[now];
            nums[now]=temp;
        }
        //int count=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};