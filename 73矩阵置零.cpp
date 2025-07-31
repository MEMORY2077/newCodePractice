#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void change(vector<vector<int>>& matrix,int x,int y){
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[x][i]!=0)matrix[x][i]=-114514;
        }
        for(int i=0;i<n;i++){
            if(matrix[i][y]!=0)matrix[i][y]=-114514;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    change(matrix,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-114514){
                    matrix[i][j]=0;
                }
            }
        }
    }
};