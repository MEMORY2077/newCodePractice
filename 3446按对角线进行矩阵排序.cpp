#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            int n=grid.size();
            for(int start=0;start<n;start++){
                bool flag=true;
                while(flag){
                    flag=false;
                    for(int i=0;start+i<n-1;i++){
                        if(grid[start+i][i]<grid[start+i+1][i+1]){
                            flag=true;
                            swap(grid[start+i][i],grid[start+i+1][i+1]);
                        }
                    }
                }
            }
            for(int start=1;start<n;start++){
                bool flag=true;
                while(flag){
                    flag=false;
                    for(int i=0;start+i<n-1;i++){
                        if(grid[i][start+i]>grid[i+1][start+i+1]){
                            flag=true;
                            swap(grid[i][start+i],grid[i+1][start+i+1]);
                        }
                    }
                }
            }
            return grid;
        }
    };