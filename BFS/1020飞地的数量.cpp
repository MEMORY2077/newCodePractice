#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numEnclaves(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            int all=0;
            vector<vector<bool>>visited(m,vector<bool>(n,false));
            queue<pair<int,int>>q;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]){
                        all++;
                        if(i==0||j==0||i==m-1||j==n-1){
                            q.push({i,j});
                            visited[i][j]=1;
                        }
                    }
                }
            }
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                if(grid[x][y]==1){
                    all--;
                }
                for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&ny>=0&&nx<m&&ny<n&&!visited[nx][ny]&&grid[nx][ny]){
                        q.push({nx,ny});
                        visited[nx][ny]=1;
                    }
                }
            }
            return all;
        }
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    };