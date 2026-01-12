#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            int step=0;
            queue<pair<int,int>>q;
            int m=maze.size();
            int n=maze[0].size();
            q.push({entrance[0],entrance[1]});
            vector<vector<int>>visited(m,vector<int>(n));
            visited[entrance[0]][entrance[1]]=1;
            int go[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
            while(!q.empty()){
                int s=q.size();
                for(int _=0;_<s;_++){
                    pair<int,int>now=q.front();
                    q.pop();
                    if(step!=0&&(now.first==0||now.first==m-1||now.second==0||now.second==n-1)){
                        return step;
                    }
                    for(int i=0;i<4;i++){
                        int nextx=now.first+go[i][0];
                        int nexty=now.second+go[i][1];
                        cout<<nextx<<' '<<nexty<<endl;
                        if(nextx<0||nextx>=m||nexty<0||nexty>=n||visited[nextx][nexty]||maze[nextx][nexty]=='+')continue;
                        visited[nextx][nexty]=1;
                        q.push({nextx,nexty});
                    }
                }
                step++;
            }
            return -1;
        }
    };