#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int shortestBridge(vector<vector<int>>& grid) {
            int n=grid.size();
            int next[4][2]={
                {0,1},{0,-1},{1,0},{-1,0}
            };
            vector<pair<int,int>>island;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        queue<pair<int,int>>q;
                        q.push({i,j});
                        grid[i][j]=-1;
                        while(!q.empty()){
                            auto [x,y]=q.front();
                            q.pop();
                            island.push_back({x,y});
                            for(int k=0;k<4;k++){
                                int nx=x+next[k][0];
                                int ny=y+next[k][1];
                                if(nx>=0&&ny>=0&&nx<n&&ny<n&&grid[nx][ny]==1){
                                    q.push({nx,ny});
                                    grid[nx][ny]=-1;
                                }
                            }
                        }
                        for(auto &&[x,y]:island){
                            q.push({x,y});
                        }
                        int step=0;
                        while(!q.empty()){
                            int s=q.size();
                            for(int i=0;i<s;i++){
                                auto [x,y]=q.front();
                                q.pop();
                                for(int k=0;k<4;k++){
                                    int nx=x+next[k][0];
                                    int ny=y+next[k][1];
                                    if(nx>=0&&ny>=0&&nx<n&&ny<n){
                                        if(grid[nx][ny]==0){
                                            q.push({nx,ny});
                                            grid[nx][ny]=-1;
                                        }
                                        else if(grid[nx][ny]==1){
                                            return step;
                                        }
                                    }
                                }
                            }
                            step++;
                        }
                    }
                }
            }
            return 0;
        }
    };