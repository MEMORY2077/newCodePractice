#include <bits/stdc++.h>
using namespace std;
//如法炮制前几天的会超时。。。
class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            int n=arr.size();
            int ans=0;
            vector<int>dp(n,1);
            for(int i=0;i<n;i++){
                //int temp=1;
                for(int j=i-1;j>=0;j--){
                    if(arr[i]==arr[j]+difference){
                        dp[i]=dp[j]+1;
                        break;
                    }
                }
                ans=max(ans,dp[i]);
            }
            return ans;
        }
    };