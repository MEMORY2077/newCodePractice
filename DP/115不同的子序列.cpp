#include <bits/stdc++.h>
//自己第一个自己思考做出的dp
//以前直接看题解遇到很抽象的测试用例没什么感觉，改范围就好了呗，今天这个纯自己写的遇到了还真挺破防的
using namespace std;
class Solution {
    public:
        int numDistinct(string s, string t) {
            int m=s.size();
            int n=t.size();
            vector<vector<unsigned long long int>>dp(n,vector<unsigned long long int>(m,0));
            if(s[0]==t[0])dp[0][0]=1;
            for(int i=1;i<m;i++){
                if(s[i]==t[0]){
                    dp[0][i]=dp[0][i-1]+1;
                }
                else dp[0][i]=dp[0][i-1];
            }

            for(int j=1;j<m;j++){
                for(int i=1;i<=j&&i<n;i++){
                    if(t[i]==s[j])dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                    else dp[i][j]=dp[i][j-1];
                }
            }
            /*for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<dp[i][j]<<' ';
                }
                cout<<endl;
            }*/
            return dp[n-1][m-1];
        }
    };