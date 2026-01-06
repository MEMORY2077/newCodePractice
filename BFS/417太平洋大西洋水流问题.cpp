#include <bits/stdc++.h>
using namespace std;
//从大西洋和太平洋引水，水往高处走，能被覆盖的就是
class Solution {
    public:
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            int n=heights.size();
            int m=heights[0].size();
            vector<vector<int>>pacific(n,vector<int>(m,false));
            vector<vector<int>>atlantic(n,vector<int>(m,false));
            queue<pair<int,int>>q;
            for(int i=0;i<n;i++){
                pacific[i][0]=1;
                q.push({i,0});
            }
            for(int i=1;i<m;i++){
                pacific[0][i]=1;
                q.push({0,i});
            }
            int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&pacific[nx][ny]!=1){
                        if(heights[x][y]<=heights[nx][ny]){
                            q.push({nx,ny});
                            pacific[nx][ny]=1;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                atlantic[i][m-1]=1;
                q.push({i,m-1});
            }
            for(int i=0;i<m-1;i++){
                atlantic[n-1][i]=1;
                q.push({n-1,i});
            }
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&atlantic[nx][ny]!=1){
                        if(heights[x][y]<=heights[nx][ny]){
                            q.push({nx,ny});
                            atlantic[nx][ny]=1;
                        }
                    }
                }
            }
            vector<vector<int>>ans;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(pacific[i][j]&&atlantic[i][j]){
                        ans.push_back({i,j});
                    }
                }
            }
            return ans;
        }
    };