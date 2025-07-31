#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>>map(2,vector<int>(2,0));
        for(auto x:nums){
            x%=2;
            for(int y=0;y<2;y++){
                map[y][x]=map[x][y]+1;
            }
        }
        int maximum=0;
        for(auto i:map){
            for(auto j:i){
                maximum=max(j,maximum);
            }
        }
        return maximum;
    }
};