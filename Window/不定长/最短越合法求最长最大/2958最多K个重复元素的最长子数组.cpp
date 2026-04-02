#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        int ans=0;
        int n=nums.size();
        int l=0;
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
            while(cnt[nums[i]]>k){
                cnt[nums[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};