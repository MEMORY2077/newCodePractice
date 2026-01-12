#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            int n=s.size();
            vector<bool>dp(n+1,false);
            unordered_set<string>dict(wordDict.begin(),wordDict.end());
            dp[0]=true;
            for(int i=1;i<=n;i++){
                for(int j=0;j<i;j++){
                    if(dp[j]&&dict.find(s.substr(j,i-j+1))!=dict.end())dp[i]=true;
                }
            }
            return dp[n];
        }
    };