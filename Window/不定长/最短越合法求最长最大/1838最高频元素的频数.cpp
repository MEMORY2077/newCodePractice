#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int ans=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            while(sum+k<nums[i]*(i-l)){
                sum-=l;
                l++;
            }
            ans=max(ans,i-l+1);
            sum+=nums[i];
        }
        return ans;
    }
};