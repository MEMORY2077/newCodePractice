#include <vector>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int ans=0;
        long long int res=0;
        int l=0;
        int n=nums.size();
        for(int r=0;r<n;r++){
            res+=nums[r];
            while((r-l+1)*res>=k){
                res-=nums[l];
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};