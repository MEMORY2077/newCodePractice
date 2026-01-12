#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    const int INFI=0x3f3f3f3f;
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
            int n=points.size();
            vector<vector<int>>grid(n+1,vector<int>(n+1,INFI));
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    if(i==j)grid[i][j]=0;
                    else{
                        grid[i][j]=grid[j][i]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    }
                }
            }
            vector<int>dist(n,INFI);
            vector<int>pre(n,-1);
            if(prim(grid,dist,pre,0))return -1;
            int ans=0;
            for(int i=0;i<n;i++){
                ans+=dist[i];
            }
            return ans;
        }
        int findmin(vector<int>&dist,vector<bool>&S){
            int v=-1;
            int mindist=INFI;
            for(int i=0;i<dist.size();i++){
                if(S[i]==0&&dist[i]<mindist){
                    v=i;
                    mindist=dist[i];
                }
            }
            return v;
        }
        bool prim(const vector<vector<int>>&grid,vector<int>&dist,vector<int>&pre,int start){
            int n=dist.size();
            vector<bool>S(n,false);
            dist[start]=0;
            for(int i=0;i<n;i++){
                int v=findmin(dist,S);
                if(v==-1)return false;
                S[v]=true;
                for(int i=0;i<n;i++){
                    if(S[i]==false&&grid[v][i]<dist[i]){
                        dist[i]=grid[v][i];
                        pre[i]=v;
                    }
                }
            }
            return true;
        }
    };