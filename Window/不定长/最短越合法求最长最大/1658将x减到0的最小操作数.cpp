#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        sum-=x;
        if(sum<0)return -1;
        //cout<<sum<<endl;
        int ans=-1;
        int res=0;
        int l=0;
        for(int i=0;i<n;i++){
            res+=nums[i];
            while(res>sum){
                res-=nums[l];
                l++;
            }
            if(res==sum)ans=max(ans,i-l+1);
        }
        if(ans<0)return ans;
        return n-ans;
    }
};