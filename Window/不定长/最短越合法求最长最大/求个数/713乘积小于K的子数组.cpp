#include <vector>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;//注意边界判断
        int n=nums.size();
        int ans=0;
        int l=0;
        int res=1;
        for(int r=0;r<n;r++){
            res*=nums[r];
            while(res>=k){
                res/=nums[l];
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};