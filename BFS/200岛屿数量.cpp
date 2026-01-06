#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            int count=0;
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<bool>>visited(m,vector<bool>(n,false));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='1'&&!visited[i][j]){
                        count++;
                        bfs(grid,visited,i,j);
                    }
                }
            }
            return count;
        }
        void bfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,int sx,int sy){
            int m=grid.size();
            int n=grid[0].size();
            queue<pair<int,int>>q;
            q.push({sx,sy});
            visited[sx][sy]=true;
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]=='1'&&!visited[nx][ny]){
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
            }
            return ;
        }
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    };