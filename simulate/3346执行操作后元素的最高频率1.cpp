#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k, int numOperations) {
            unordered_map<int,int>count;
            unordered_set<int>(nums.begin(),nums.end());
            //sort(nums.begin(),nums.end());
            int ans=0;
            int n=nums.size();
            for(int num:nums){
                for(int i=-k;i<=k;i++){
                    count[num+i]++;
                }
            }
            for(auto [_,x]:count){
                ans=max(ans,min(numOperations,x));
            }
            return ans;
        }
    };