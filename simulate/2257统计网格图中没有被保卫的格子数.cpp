#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
    public:
        int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
            vector<vector<int>>amap(m,vector<int>(n,0));
            for(auto wall:walls){
                amap[wall[0]][wall[1]]=-1;
            }
            for(auto guard:guards){
                amap[guard[0]][guard[1]]=-1;
            }
            int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
            for(auto guard:guards){
                for(int i=0;i<4;i++){
                    int x=guard[0];
                    int y=guard[1];
                    while(1){
                        x+=dir[i][0];
                        y+=dir[i][1];
                        if(x<0||x>=m||y<0||y>=n||amap[x][y]==-1)break;//撞墙了
                        amap[x][y]=1;//可以看见
                    }
                }
            }
            int ans=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(amap[i][j]==0)ans++;
                }
            }
            return ans;
        }
    };