#include <vector>
#include <iostream>
#include <array>
using namespace std;
class Solution {
    public:
        //m,n,desti,turn
        int m,n;
        vector<vector<array<array<int,2>,4>>>MEMORY;
        int desti[4][2]={{-1,1},{1,1},{1,-1},{-1,-1}};
        int lenOfVDiagonal(vector<vector<int>>& grid) {
            m=grid.size();
            n=grid[0].size();
            MEMORY=vector<vector<array<array<int,2>,4>>>(m,vector<array<array<int,2>,4>>(n));
            int ans=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        for(int k=0;k<4;k++){
                            ans=max(ans,dfs(grid,i,j,k,true,2)+1);
                        }
                    }
                }
            }
            return ans;
        }
        int dfs(vector<vector<int>>&grid,int i,int j,int k,bool canTurn,int target){
            i+=desti[k][0];
            j+=desti[k][1];
            if(i<0||j<0||i>=m||j>=n||grid[i][j]!=target){
                return 0;
            }
            int &res=MEMORY[i][j][k][canTurn];
            if(res!=0){
                return res;
            }
            res=dfs(grid,i,j,k,canTurn,2-target)+1;
            if(canTurn){
                res=max(res,dfs(grid,i,j,(k+1)%4,false,2-target)+1);
            }
            return res;
        }
    };