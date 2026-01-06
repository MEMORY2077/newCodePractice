#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
            int n=obstacles.size();
            vector<int>dp;
            vector<int>ans;
            for(int ob:obstacles){
                if(dp.empty()||ob>=dp.back()){
                    dp.push_back(ob);
                    ans.push_back(dp.size());
                }
                else{
                int j=upper_bound(dp.begin(),dp.end(),ob)-dp.begin();
                ans.push_back(j+1);
                dp[j]=ob;
                }
            }
            return ans;
        }
    };