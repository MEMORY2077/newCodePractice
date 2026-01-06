#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        int findMaxForm(vector<string>& strs, int m, int n) {
            int N=strs.size();
            vector<vector<int>>counts(N,vector<int>(2,0));
            for(int i=0;i<N;i++){
                for(char now:strs[i]){
                    if(now=='0')counts[i][0]++;
                    else counts[i][1]++;
                }
            }
            vector<vector<int>>dp(m,vector<int>(n,0));
            //dp[i][j]指最多i个0和j个1的最大子集大小
            for(vector<int>count:counts){
                for(int i=m;i>=count[0];i--){
                    for(int j=n;j>=count[1];j--){
                        dp[i][j]=max(dp[i][j],dp[i-count[0]][j-count[1]]+1);
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };