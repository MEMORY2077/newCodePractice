#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<int>cnt(2,0);
        int l=0;
        for(int i=0;i<n;i++){
            if(nums[i])cnt[1]++;
            else cnt[0]++;
            while(cnt[0]>k){
                cnt[nums[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};