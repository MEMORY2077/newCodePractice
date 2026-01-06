#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            sort(pairs.begin(),pairs.end());
            int n=pairs.size();
            int maximum=1;
            vector<int>dp(n,1);
            for(int i=1;i<n;i++){
                int temp=1;
                for(int j=0;j<i;j++){
                    if(pairs[i][0]>pairs[j][1]){
                        temp=max(temp,dp[j]+1);
                    }
                }
                dp[i]=temp;
                maximum=max(maximum,dp[i]);
            }
            return maximum;
        }
    };