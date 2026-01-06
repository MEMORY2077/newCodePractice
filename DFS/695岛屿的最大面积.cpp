#include <vector>
#include <algorithm>
using std::vector;
class Solution {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            int ans=0;
            vector<vector<bool>>visited(m,vector<bool>(n,false));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]&&!visited[i][j]){
                        count=0;
                        visited[i][j]=1;
                        dfs(grid,visited,i,j);
                        ans=std::max(ans,count);                        
                    }
                }
            }
            return ans;
        }
        void dfs(vector<vector<int>>grid,vector<vector<bool>>&visited,int sx,int sy){
            count++;
            int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
            for(int i=0;i<4;i++){
                int nx=sx+dir[i][0];
                int ny=sy+dir[i][1];
                if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&grid[nx][ny]&&!visited[nx][ny]){
                    visited[nx][ny]=1;
                    dfs(grid,visited,nx,ny);
                }
            }
        }
        int count=0;
    };