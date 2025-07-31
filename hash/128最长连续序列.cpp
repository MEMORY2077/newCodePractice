#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>map(nums.begin(),nums.end());
        int ans=0;
        for(auto i:map){
            if(map.find(i-1)!=map.end()){
                continue;
            }
            int y=i+1;
            while(map.find(y)!=map.end()){
                y++;
            }
            ans=max(ans,y-i);
        }
        return ans;
    }
};