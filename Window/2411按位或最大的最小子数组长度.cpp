#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int left_or=0,suf_or=0;
        int right=n-1,bottom=n-1;
        for(int left=n-1;left>=0;left--){
            suf_or|=nums[left];
            left_or|=nums[left];
            while(right>=left&&(left_or|nums[right])==suf_or){
                right--;
                if(bottom>right){
                    for(int i=left+1;i<=right;i++){
                        nums[i]|=nums[i-1];
                    }
                    bottom=left;
                    left_or=0;
                }
            }
            ans[left]=right-left+2;
        }
        return ans;
    }
};