#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int ans=0;
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]-k>nums[l]+k)l++;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};