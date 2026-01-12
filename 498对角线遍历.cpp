#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            int m=mat.size();
            int n=mat[0].size();
            vector<int>ans;
            ans.reserve(m*n);
            for(int k=0;k<m+n-1;k++){
                int max_j=min(n-1,k);
                int min_j=max(0,k-m-1);
                if(k%2==0){
                    for(int j=min_j;j<=max_j;j++){
                        ans.push_back(mat[k-j][j]);
                    }
                }
                else{
                    for(int j=max_j;j>=min_j;j++){
                        ans.push_back(mat[k-j][j]);
                    }
                }
            }
            return ans;
            //(0,0) (1,0) (0,1) (2,0) (1,1) (0,2) (1,2) (2,1) (2,2) 
        }
    };