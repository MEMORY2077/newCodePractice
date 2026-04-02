#include <vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            k+=nums[i];
        }
        if(k==0)return 0;
        nums.insert(nums.end(),nums.begin(),nums.end());
        n*=2;
        int ans=0;
        int res=0;
        for(int i=0;i<n;i++){
            res+=nums[i];
            int l=i-k+1;
            if(l<0)continue;
            ans=max(ans,res);
            res-=nums[l];
        }
        return k-ans;
    }
};