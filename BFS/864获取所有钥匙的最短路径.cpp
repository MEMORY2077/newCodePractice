#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int shortestPathAllKeys(vector<string>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            int sx=0;//起点
            int sy=0;
            unordered_map<char,int>key2idx;
            int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='@'){
                        sx=i;
                        sy=j;
                    }
                    else{
                        if(islower(grid[i][j])&&!key2idx.count(grid[i][j])){
                            int idx=key2idx.size();
                            key2idx[grid[i][j]]=idx;
                        }
                    }
                }
            }
            queue<tuple<int,int,int>>q;
            vector<vector<vector<int>>>dist(m,vector<vector<int>>(n,vector<int>(1<<key2idx.size(),-1)));
            q.emplace(sx,sy,0);
            dist[sx][sy][0]=0;
            while(!q.empty()){
                auto [x,y,mask]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]!='#'){
                        if(grid[nx][ny]=='.'||grid[nx][ny]=='@'){
                            if(dist[nx][ny][mask]==-1){
                                dist[nx][ny][mask]=dist[x][y][mask]+1;
                                q.push({nx,ny,mask});
                            }
                        }
                        else if(islower(grid[nx][ny])){
                            int idx=key2idx[grid[nx][ny]];
                            if(dist[nx][ny][mask|(1<<idx)]==-1){
                                dist[nx][ny][mask|(1<<idx)]=dist[x][y][mask]+1;
                                if((mask|(1<<idx))==(1<<key2idx.size())-1){
                                    return dist[nx][ny][mask|1<<idx];
                                }
                                q.push({nx,ny,mask|(1<<idx)});
                            }
                        }
                        else{
                            int idx=key2idx[tolower(grid[nx][ny])];
                            if((mask&(1<<idx))&&dist[nx][ny][mask]==-1){
                                dist[nx][ny][mask]=dist[x][y][mask]+1;
                                q.push({nx,ny,mask});
                            }
                        }
                    }
                }
            }
            return -1;
        }
    };