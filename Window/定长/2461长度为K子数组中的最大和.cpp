#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int>has;
        long long ans=0;
        long long res=0;
        int n=nums.size();
        int l=0;
        for(int r=0;r<n;r++){
            while(has.count(nums[r])){
                res-=nums[l];
                has.erase(nums[l]);
                l++;
            }
            has.emplace(nums[r]);
            res+=nums[r];
            if(r-l+1<k)continue;
            ans=max(ans,res);
            res-=nums[l];
            has.erase(nums[l]);
        }
        return ans;
    }
};