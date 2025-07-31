#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int Mnum=INT_MIN;
        int ans=0;
        int n=nums.size();
        for(int left=0;left<n;left++){
            if(nums[left]>=Mnum){
                if(nums[left]>Mnum)ans=0;
                int length=1;
                Mnum=nums[left];
                int right=left+1;
                for(right;right<n;right++){
                    if(nums[right]==nums[left]){
                        length++;
                    }
                    else break;
                }
                ans=max(ans,length);
                left=right;
            }
        }
        return ans;
    }
};