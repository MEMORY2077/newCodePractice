#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int left=INT_MAX;
        int right=0;
        int top=INT_MAX;
        int bottom=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    left=min(left,i);
                    right=max(right,i);
                    top=min(top,j);
                    bottom=max(bottom,j);
                }
            }
        }
        return (right-left+1)*(bottom-top+1);      
    }
};