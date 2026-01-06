#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            int maxnum=0;
            for(int now:nums){
                maxnum=max(now,maxnum);
            }
            vector<int>newnums(maxnum+1,0);
            for(int now:nums){
                newnums[now]+=now;
            }
            int a=newnums[0];
            int b=max(newnums[1],newnums[0]);
            for(int i=2;i<=maxnum;i++){
                int c=max(b,a+newnums[i]);
                a=b;
                b=c;
            }
            //for(int i=0;i<=maxnum;i++){
            //    cout<<dp[i]<<' ';
            //}            
            return b;
        }
    };