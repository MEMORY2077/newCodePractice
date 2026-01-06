#include <vector>
#include <queue>
using namespace std;
class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n=grid.size();
            if(grid[0][0]==1||grid[n-1][n-1]==1)return -1;
            int dir[8][2]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
            queue<pair<int,int>>q;
            q.push({0,0});
            grid[0][0]=1;
            int step=1;
            while(!q.empty()){
                int zs=q.size();
                for(int _=0;_<zs;_++){
                    auto [x,y]=q.front();
                    q.pop();
                    if(x==n-1&&y==n-1)return step;
                    for(int i=0;i<8;i++){
                        int nx=x+dir[i][0];
                        int ny=y+dir[i][1];
                        if(nx>=0&&ny>=0&&nx<n&&ny<n&&!grid[nx][ny]){
                            q.push({nx,ny});
                            grid[nx][ny]=1;
                        }
                    }
                }
                step++;
            }
            return -1;
        }
    };