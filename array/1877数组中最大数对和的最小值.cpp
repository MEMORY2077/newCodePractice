#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int c=n/2;
        int ans=0;
        for(int i=0;i<c;i++){
            ans=max(ans,nums[i]+nums[n-i-1]);
        }
        return ans;
    }
};