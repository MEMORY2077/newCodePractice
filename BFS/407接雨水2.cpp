#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int dist[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int trapRainWater(vector<vector<int>>& heightMap) {
            priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
            int m=heightMap.size();
            int n=heightMap[0].size();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0||i==m-1||j==0||j==n-1){
                        pq.emplace(heightMap[i][j],i,j);
                        heightMap[i][j]=-1;
                    }
                }
            }
            int ans=0;
            while(!pq.empty()){
                auto [min_height,i,j]=pq.top();
                pq.pop();
                for(auto&[nx,ny]:dist){
                    int x=i+nx;
                    int y=j+ny;
                    if(x>=0&&x<m&&y>=0&&y<n&&heightMap[x][y]>=0){
                        ans+=max(min_height-heightMap[x][y],0);
                        pq.emplace(max(min_height,heightMap[x][y]),x,y);
                        heightMap[x][y]=-1;
                    }
                }
            }
            return ans;
        }
    };