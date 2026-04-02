#include <vector>
using namespace std;
//下标遍历，挺有意思
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>pos_list(n+1,vector<int>());
        for(int i=0;i<n;i++){
            int x=nums[i];
            pos_list[x].push_back(i);
        }   
        int ans=0;
        for(auto pos:pos_list){
            int l=0;
            for(int r=0;r<pos.size();r++){
                while(pos[r]-pos[l]-r+l>k){
                    l++;
                }
                ans=max(ans,r-l+1);
            }
        }
        return ans;
    }
};