#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>pairs;
        for(int i=0;i<nums.size();i++){
            for(int x:nums[i]){
                pairs.emplace_back(x,i);
            }
        }
        sort(pairs.begin(),pairs.end());
        int empty=nums.size();
        vector<int>cnt(empty);
        int left=0;
        int ans_l=pairs[0].first;
        int ans_r=pairs.back().first;
        for(auto[r,i]:pairs){
            if(cnt[i]==0){
                empty--;
            }
            cnt[i]++;
            while(empty==0){
                auto [l,j]=pairs[left];
                if(r-l<ans_r-ans_l){
                    ans_r=r;
                    ans_l=l;
                }
                cnt[j]--;
                if(cnt[j]==0)empty++;
                left++;
            }
        }
        return {ans_l,ans_r};
    }
};