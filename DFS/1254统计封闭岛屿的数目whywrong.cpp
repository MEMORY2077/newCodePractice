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
                    if(!visited[i][j]&&!grid[i][j]){
                        //visited[i][j]=true;
                        if(dfs(grid,visited,i,j))count++;
                    }
                }
            }
            return count;
        }
        bool dfs(vector<vector<int>>&grid,vector<vector<bool>>&visited,int sx,int sy){
            visited[sx][sy]=1;
            if(sx>=grid.size()-1||sx<=0||sy<=0||sy>=grid[0].size()-1){
                //cout<<1<<endl;
                return false;
            }
            int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
            for(int i=0;i<4;i++){
                int nx=sx+dir[i][0];
                int ny=sy+dir[i][1];
                //cout<<nx<<' '<<ny<<endl;
                if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&!visited[nx][ny]&&!grid[nx][ny]){
                    //visited[nx][ny]=1;
                    if(!dfs(grid,visited,nx,ny))return false;
                }
            }
            return true;
        }
    };