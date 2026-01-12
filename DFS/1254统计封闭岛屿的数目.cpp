#include <vector>
using std::vector;
class Solution {
    public:
        int closedIsland(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<bool>>visited(m,vector<bool>(n,false));
            int count=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!grid[i][j]){
                        //visited[i][j]=true;
                        if(dfs(grid,i,j))count++;
                    }
                }
            }
            return count;
        }
        bool dfs(vector<vector<int>>&grid,int sx,int sy){
            if(sx>=grid.size()||sx<0||sy<0||sy>=grid[0].size()){
                return false;
            }
            if(grid[sx][sy])return true;
            grid[sx][sy]=-1;
            int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
            vector<bool>c(4,false);
            for(int i=0;i<4;i++){
                int nx=sx+dir[i][0];
                int ny=sy+dir[i][1];
                //cout<<nx<<' '<<ny<<endl;
                    //visited[nx][ny]=1;
                    if(dfs(grid,nx,ny))c[i]=true;
                
            }
            return c[0]&&c[1]&&c[2]&&c[3];
        }
    };