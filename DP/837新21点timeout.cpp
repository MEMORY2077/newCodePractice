#include <vector>
using namespace std;
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        dp=vector<double>(n+1,0);
        return dfs(n,k,maxPts,0);
    }
    double dfs(int n,int k,int maxPts,int now){
        if(now>n)return 0;
        if(now<=n&&now>=k){
            dp[now]=1;
            return 1;
        }
        double ans;
        if(dp[now]!=0)return dp[now];
        for(int i=now+1;i<=now+maxPts;i++){
            ans+=dfs(n,k,maxPts,i);
        }
        dp[now]=ans/maxPts;
        return dp[now];
    }
    vector<double>dp;
};