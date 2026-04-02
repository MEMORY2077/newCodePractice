#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=x,j=x+k-1;i<j;i++,j--){
            vector<int>temp(k);
            for(int l=0;l<k;l++){
                temp[l]=grid[i][y+l];
            }
            for(int l=0;l<k;l++){
                grid[i][y+l]=grid[j][y+l];
            }
            for(int l=0;l<k;l++){
                grid[j][y+l]=temp[l];
            }
        }
        return grid;
    }
};