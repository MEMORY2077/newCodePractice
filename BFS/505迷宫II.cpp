#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
class Solution {
public:
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        queue<pair<int,int>>q;
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>>distance(m,vector<int>(n,INT_MAX));
        distance[start[0]][start[1]]=0;
        q.push({start[0],start[1]});
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int dis=0;
                int dx=x;
                int dy=y;
                while(dx+dir[i][0]>=0&&dx+dir[i][0]<m&&dy+dir[i][1]>=0&&dy+dir[i][1]<n&&maze[dx+dir[i][0]][dy+dir[i][1]]!=1){
                    dx+=dir[i][0];
                    dy+=dir[i][1];
                    dis++;
                }
                if(dis+distance[x][y]<distance[dx][dy]){
                    q.push({dx,dy});
                    distance[dx][dy]=dis+distance[x][y];
                }
            }
        }
        if(distance[dest[0]][dest[1]]==INT_MAX)return -1;
        return distance[dest[0]][dest[1]];
    }
};