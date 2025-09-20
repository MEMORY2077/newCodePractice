#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int u=0;
        int d=n-1;
        int mid;
        int row=0;
        while(u<=d){
            mid=(d-u)/2+u;
            if(matrix[mid][m-1]>=target){
                row=mid;
                d=mid-1;
                continue;
            };
            if(matrix[mid][m-1]<target){
                u=mid+1;
                continue;
            }
        }
        int l=0;
        int r=m-1;
        //cout<<row<<endl;
        while(l<=r){
            mid=(r-l)/2+l;
            if(matrix[row][mid]==target)return true;
            if(matrix[row][mid]>target){
                r=mid-1;
                continue;
            }
            if(matrix[row][mid]<target){
                l=mid+1;
                continue;
            }
        }
        return false;
    }
};