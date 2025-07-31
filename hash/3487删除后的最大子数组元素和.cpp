#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>h(nums.begin(),nums.end());
        int ans=0;
        for(auto i:h){
            if(i>0){
                ans+=i;
            }
        }
        if(ans==0){
            int maximum=INT_MIN;
            for(auto i:h){
                maximum=max(i,maximum);
            }   
            ans=maximum;
        }
        return ans;
    }
};