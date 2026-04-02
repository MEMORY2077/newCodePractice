#include <vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=-20000;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int l=i-k+1;
            if(l<0)continue;
            ans=max(ans,1.0*sum/k);
            sum-=nums[l];
        }
        return ans;
    }
};