//题解有一个说可以reverse一下然后求两个串的最长公共子序列的，不知道真的假的，回头有机会学习一下这个思路
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n=s.size();
            vector<vector<int>>dp(n,vector<int>(n,0));
            for(int i=n-1;i>=0;i--){
                dp[i][i]=1;
                char c1=s[i];
                for(int j=i+1;j<n;j++){
                    char c2=s[j];
                    if(c1==c2)dp[i][j]=dp[i+1][j-1]+2;
                    else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
            return dp[0][n-1];
        }
    };