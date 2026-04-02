#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n+1,0);
        vector<int>last(n+1,0);
        pre[0]=1;
        last[n]=1;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]*nums[i-1];
            last[n-i]=last[n-i+1]*nums[n-i];
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*last[i+1];
        }
        return ans;
    }
};