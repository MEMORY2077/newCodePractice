#include <vector>
#include <limits.h>
using namespace std;
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n=triangle.size();
            vector<vector<int>>dp=triangle;
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(j==i-1){
                        dp[i][j]=dp[i-1][j]+triangle[i][j];
                    }
                    else{
                        dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+triangle[i][j];
                    }
                }
            }
            int minimum=INT_MAX;
            for(int i=0;i<n;i++){
                minimum=min(dp[n-1][i],minimum);
            }
            return minimum;
        }
    };