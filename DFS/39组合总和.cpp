#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>now;
        //sort(candidates.begin(),candidates.end());
        dfs(candidates,now,target,0);
        return ans;
    }
    void dfs(vector<int>&candidates,vector<int>now,int target,int next){
        if(target==0){
            ans.push_back(now);
            return;
        }
        if(target<0)return;
        for(int i=next;i<candidates.size();i++){
            now.push_back(candidates[i]);
            dfs(candidates,now,target-candidates[i],i);
            now.pop_back();
        }
        return;
    }
    vector<vector<int>>ans;
};