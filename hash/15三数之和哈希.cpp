#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
//排序后看i和i-1是否一样，然后看nums[j]是否用过，就能避免重复
//固定x，转化成两数之和问题
class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i-1]==nums[i])continue;//用过了
            if(nums[i]+nums[i+1]+nums[i+2]>0)break;//优化1：已经不可能了，退出
            if(nums[i]+nums[n-2]+nums[n-1]<0)continue;//优化2：这个i太小了，内层不可能有
            unordered_set<int>map;
            unordered_set<int>samej;
            for(int j=i+1;j<n;j++){
                if(samej.find(nums[j])!=samej.end())continue;//用过了
                if(map.find(-nums[i]-nums[j])==map.end()){
                    map.emplace(nums[j]);
                }
                else {
                    ans.push_back({nums[i],nums[j],-nums[i]-nums[j]});

                    samej.emplace(nums[j]);
                }
            }
        }
        return ans;
    }
};