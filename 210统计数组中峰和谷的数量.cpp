#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            int left=0;
            for(int j=i-1;i>=0;i--){
                if(nums[j]>nums[i]){
                    left=1;
                    break;
                }
                if(nums[j]<nums[i]){
                    left=-1;
                    break;
                }
            }
            int right=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    right=1;
                    break;
                }
                if(nums[j]<nums[i]){
                    right=-1;
                    break;
                }
            }
            if(left==right){
                ans++;
            }
        }
        return ans;
    }
};