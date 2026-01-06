#include <vector>
using namespace std;
class Solution {
    const int INF=0x3f3f3f3f;
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<int>>dp(k+2,vector<int>(n,INF));
            dp[0][src]=0;
            for(int t=1;t<=k+1;t++){
                for(auto flight:flights){
                    int start=flight[0];
                    int to=flight[1];
                    int price=flight[2];
                    dp[t][to]=min(dp[t][to],dp[t-1][start]+price);
                }
            }
            int ans=INF;
            for(int i=0;i<=k+1;i++){
                ans=min(dp[i][dst],ans);
            }
            if(ans==INF)return -1;
            return ans;
        }
    };