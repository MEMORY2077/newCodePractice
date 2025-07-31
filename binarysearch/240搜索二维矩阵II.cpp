#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        int col=n-1;
        while(col>=0&&row<n){
            if(matrix[row][col]==target)return true;
            if(matrix[row][col]<target){
                row++;
                continue;
            }
            if(matrix[row][col]>target){
                col--;
                continue;
            }
        }
        return false;
    }
};