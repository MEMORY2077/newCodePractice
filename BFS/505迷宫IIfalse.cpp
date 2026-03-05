#include <vector>
#include <queue>
#include <limits.h>
//visited没法保证到达的位置是最短的路径
using namespace std;
class Solution {
public:
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int,int>>q;
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<int>lq;
        q.push({start[0],start[1]});
        lq.push(0);
        int ans=INT_MAX;
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            int dis=lq.front();
            lq.pop();
            if(x==destination[0]&&y==destination[1])ans=min(ans,dis);
            visited[x][y]=1;
            for(int i=0;i<4;i++){
                int ndis=dis;
                int dx=x;
                int dy=y;
                while(dx+dir[i][0]>=0&&dx+dir[i][0]<m&&dy+dir[i][1]>=0&&dy+dir[i][1]<n&&maze[dx+dir[i][0]][dy+dir[i][1]]!=1){
                    dx+=dir[i][0];
                    dy+=dir[i][1];
                    ndis++;
                }
                if(visited[dx][dy]==0){
                    q.push({dx,dy});
                    lq.push(ndis);
                    //visited[dx][dy]=1;
                }
            }
        }
        if(ans!=INT_MAX)return ans;
        return -1;
    }
};