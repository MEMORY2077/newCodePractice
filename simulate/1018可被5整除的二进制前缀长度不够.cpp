//评论区说不会有人真傻乎乎模拟，然后超空间吧😎
///TAT
#include <vector>
using namespace std;
class Solution {
    public:
        vector<bool> prefixesDivBy5(vector<int>& nums) {
            int n=nums.size();
            vector<bool>ans(n,false);
            unsigned long long int now=0;
            for(int i=0;i<n;i++){
                now<<=1;
                now|=nums[i];
                if(now%5==0)ans[i]=true;
            }
            return ans;
        }
    };