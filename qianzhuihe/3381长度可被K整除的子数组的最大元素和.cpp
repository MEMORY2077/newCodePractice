#include <vector>
#include <limits.h>
using namespace std;
class Solution {
    public:
        long long maxSubarraySum(vector<int>& nums, int k) {
            int n=nums.size();
            vector<long long int>pre(n+1,0);
            for(int i=0;i<n;i++){
                pre[i+1]=pre[i]+nums[i];
            }
            vector<long long>min_s(k,LLONG_MAX/2);
            long long ans=LLONG_MIN;
            for(int j=0;j<=n;j++){
                int i=j%k;
                ans=max(ans,pre[j]-min_s[i]);
                min_s[i]=min(min_s[i],pre[j]);
            }
            return ans;
        }
    };