#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int>has;
        long long ans=0;
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            has[nums[i]]+=1;
            sum +=nums[i];
            int l =i-k+1;
            if(l<0)continue;
            if(has.size()>=m)ans=max(ans,sum);
            sum-=nums[l];
            has[nums[l]]-=1;
            if(has[nums[l]]<=0)has.erase(nums[l]);
        }
        return ans;
    }
};