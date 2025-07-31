#include <iostream>
#include <vector>
using namespace std;
//为什么不让我用除法/(ㄒoㄒ)/~~
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>last(n,0);
        pre[0]=nums[0];
        last[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]*pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            last[i]=nums[i]*last[i+1];
        }
        vector<int>ans(n,0);
        for(int i=1;i<n-1;i++){
            ans[i]=pre[i-1]*last[i+1];
        }
        ans[0]=last[1];
        ans[n-1]=pre[n-2];
        return ans;
    }
};