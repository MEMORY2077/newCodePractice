#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dict[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>lan;
        int fresh=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2)lan.push({i,j});
            }
        }
        int day=0;
        while(!lan.empty()&&fresh!=0){
            day++;
            int z=lan.size();
            while(z>0){
                auto now=lan.front();
                lan.pop();
                for(int i=0;i<4;i++){
                    int nx=now.first+dict[i][0];
                    int ny=now.second+dict[i][1];
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        lan.push({nx,ny});
                    }
                }
                z--;
            }
        }
        if(fresh!=0)return -1;
        return day;
    }
};