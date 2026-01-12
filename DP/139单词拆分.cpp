#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string>wordHash(wordDict.begin(),wordDict.end());
            int n=s.size();
            vector<bool>dp(n+1);
            dp[0]=true;
            for(int i=1;i<=n;i++){
                for(int j=0;j<i;j++){
                    if(dp[j]&&wordHash.find(s.substr(j,i-j))!=wordHash.end()){
                        dp[i]=true;
                    }
                }
            }
            return dp[n];
        }
    };