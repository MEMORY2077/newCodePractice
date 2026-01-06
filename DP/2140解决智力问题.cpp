#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n=questions.size();
            vector<long long int>dp(n,0);
            dp[n-1]=questions[n-1][0];
            for(int i=n-2;i>=0;i--){
                int next=questions[i][1]+i+1;
                if(next<n){
                    dp[i]=max(dp[i+1],dp[next]+(long long int)questions[i][0]);
                }
                else dp[i]=max(dp[i+1],(long long int)questions[i][0]);
            }
            return dp[0];
        }
    };