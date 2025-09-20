#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        bool have0=false;
        int ans=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            if(have0&&nums[right]==0){
                while(left<=right){
                    if(nums[left]==0){
                        have0=false;
                        left++;
                        break;
                    }
                    left++;
                }
            }
            else{
                if(nums[right]==0){
                    have0=true;
                }
                right++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};