#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static bool us2sort(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),us2sort);
        vector<vector<int>>ans;
        for(auto now:intervals){
            if(!ans.empty()&&ans.back()[1]>=now[0]){
                ans.back()[1]=max(now[1],ans.back()[1]);
            }
            else ans.push_back(now);
        }
        return ans;
    }
};