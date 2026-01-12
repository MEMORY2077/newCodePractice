#include <bits/stdc++.h>
using namespace std;
//1找0会超时，0找1
class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int m=mat.size();
            int n=mat[0].size();
            queue<pair<int,int>>q;
            vector<vector<bool>>visited(m,vector<bool>(n,false));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!mat[i][j]){q.push({i,j});
                       visited[i][j]=true;
                    }
                }
            }
            int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
            vector<vector<int>>ans(m,vector<int>(n,0));
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&!visited[nx][ny]){
                        ans[nx][ny]=ans[x][y]+1;
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
            }
            return ans;
        }
    };