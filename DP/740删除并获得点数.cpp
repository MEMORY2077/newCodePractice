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
            vector<int>dp(maxnum+1,0);
            dp[0]=newnums[0];
            dp[1]=max(newnums[1],newnums[0]);
            for(int i=2;i<=maxnum;i++){
                dp[i]=max(dp[i-1],dp[i-2]+newnums[i]);
            }
            //for(int i=0;i<=maxnum;i++){
            //    cout<<dp[i]<<' ';
            //}            
            return dp[maxnum];
        }
    };