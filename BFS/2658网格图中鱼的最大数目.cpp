#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int p[4][2]={
        {0,-1},{0,1},{1,0},{-1,0}
    };
    int findMaxFish(vector<vector<int>>& grid) {
        int maximum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
                int count=0;
                queue<pair<int,int>>aqueue;
                if(grid[i][j]>0)aqueue.push({i,j});
                visited[i][j]=1;
                while(!aqueue.empty()){
                    auto now=aqueue.front();
                    int x=now.first;
                    int y=now.second;
                    aqueue.pop();
                    count+=grid[x][y];

                    for(int h=0;h<4;h++){
                        int px=x+p[h][0];
                        int py=y+p[h][1];
                        if(px>=0&&px<grid.size()&&py>=0&&py<grid[0].size()&&visited[px][py]==0){
                            if(grid[px][py]>0){
                                aqueue.push({px,py});
                                visited[px][py]=1;
                            }
                        }
                    }
                }
                maximum=max(maximum,count);
            }
        }
        return maximum;
    }
};