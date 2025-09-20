#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>now;
        dfs(nums,now,0);
        return ans;
    }
    void dfs(vector<int>&nums,vector<int>now,int next){
        ans.push_back(now);
        if(next==nums.size()){
            return;
        }
        for(int i=next;i<nums.size();i++){
            now.push_back(nums[i]);
            dfs(nums,now,i+1);
            now.pop_back();
        }
        return;
    }
    vector<vector<int>>ans;
};