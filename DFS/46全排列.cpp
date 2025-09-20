#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used=vector<bool>(nums.size(),false);
        vector<int>now;
        dfs(nums,now);
        return ans;
    }
    void dfs(vector<int>&nums,vector<int>now){
        if(now.size()==nums.size()){
            ans.push_back(now);
            return;
        }
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                used[i]=true;
                now.push_back(nums[i]);
                dfs(nums,now);
                now.pop_back();
                used[i]=false;
            }
        }
        return ;
    }
    vector<vector<int>>ans;
    vector<bool>used;
};