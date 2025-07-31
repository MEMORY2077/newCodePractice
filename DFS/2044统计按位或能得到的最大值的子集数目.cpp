#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        dfs(nums,0,0);
        return ans;
    }
    int maximum=INT_MIN;
    int ans=0;
    void dfs(vector<int>&nums,int now,int sum){
        if(sum==maximum){
            ans++;
        }
        else if(sum>maximum){
            ans=1;
            maximum=sum;
        }
        for(int i=now;i<nums.size();i++){
            dfs(nums,i+1,sum|nums[i]);
        }
        return;
    }
};