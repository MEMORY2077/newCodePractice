#include <vector>
using namespace std;
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>dp(n+1,0);
        double s=0;
        for(int i=n;i>=0;i--){
            if(i>=k)dp[i]=1;
            else dp[i]=s/maxPts;
            s+=dp[i];
            if(i+maxPts<=n){
                s-=dp[i+maxPts];
            }
        }
        return dp[0];
    }
};