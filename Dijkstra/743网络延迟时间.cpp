#include<vector>
using namespace std;
class Solution {
    public:
        const int INF=0x3f3f3f3f;
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            map=vector<vector<int>>(n+1,vector<int>(n+1,INF));
            visited=vector<int>(n+1,0);
            for(vector<int>now:times){
                map[now[0]][now[1]]=now[2];
            }
            if(!Dijkstra(k,n))return -1;
            int ans=0;
            for(int i=1;i<=n;i++){
                ans=max(ans,dist[i]);
            }
            return ans;
        }
    private:
        vector<vector<int>>map;
        vector<int>visited;
        vector<int>dist;
        int findmin(const vector<int>&S,int n){
            int k=-1;
            int mindist=INF;
            for(int i=1;i<=n;i++){
                if(S[i]==0&&dist[i]<mindist){
                    k=i;
                    mindist=dist[i];
                }
            }
            return k;
        }
        bool Dijkstra(int start,int n){
            dist=vector<int>(n+1,INF);
            vector<int>S(n+1,0);
            dist[start]=0;
            for(int i=0;i<n;i++){
                int v=findmin(S,n);
                if(v==-1)return false;
                S[v]=1;
                for(int j=0;j<=n;j++){
                    if(map[v][j]!=INF){
                        dist[j]=min(dist[j],dist[v]+map[v][j]);
                    }
                }
            }
            return true;
        }
    };