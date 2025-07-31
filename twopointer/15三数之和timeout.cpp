#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                auto anon=map.find(-(nums[i]+nums[j]));
                if(anon!=map.end()&&anon->second>j){
                    vector<int>temp={nums[i],nums[j],anon->first};
                    sort(temp.begin(),temp.end());
                    if(check(temp)){
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
    bool check(vector<int>&temp){
        for(auto now:ans){
            if(temp==now)return false;
        }
        return true;
    }
};