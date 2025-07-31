#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(k,0));
        for(auto x:nums){
            x%=k;
            for(int y=0;y<k;y++){
                dp[y][x]=dp[x][y]+1;
            }
        }
        int maximum=0;
        for(auto i:dp){
            for(auto j:i){
                maximum=max(j,maximum);
            }
        }
        return maximum;
    }
};