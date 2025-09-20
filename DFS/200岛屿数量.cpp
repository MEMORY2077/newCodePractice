#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>step={{0,1},{0,-1},{1,0},{-1,0}};
        int ans=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    //visited[now.first][now.second]=1;
                    visited[i][j]=1;
                    while(!q.empty()){
                        pair<int,int>now=q.front();
                        q.pop();
                        for(auto next:step){
                            //cout<<"MEMORY"<<next[0]<<' '<<next[1]<<endl;
                            int nx=now.first+next[0];
                            int ny=now.second+next[1];
                            if(nx>=0&&ny>=0&&nx<n&&ny<m&&visited[nx][ny]==0&&grid[nx][ny]=='1'){
                                q.push({nx,ny});
                                visited[nx][ny]=1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};