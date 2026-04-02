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
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            unordered_set<int>map;
            for(int j=1;j<n;j++){
                if(map.find(-nums[i]-nums[j])==map.end()){
                    map.emplace(-nums[i]-nums[j]);
                }
                else {
                    vector<int>temp={nums[i],nums[j],-nums[i]-nums[j]};
                    sort(temp.begin(),temp.end());
                    if(check(temp)){
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
    bool check(vector<int>temp){
        for(auto i:ans){
            if(i==temp)return false;
        }
        return true;
    }
};