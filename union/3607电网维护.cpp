#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Union{
    vector<int>parents;
    public:
        Union(int n):parents(vector<int>(n,-1)){}
        int find(int x){
            if(parents[x]<0)return x;
            parents[x]=find(parents[x]);
            return parents[x];
        }
        void uu(int x,int y){
            int fx=find(x);
            int fy=find(y);
            if(fx==fy)return;
            if(parents[fx]>parents[fy]){
                //cout<<1<<endl;
                //parents[fy]-=parents[fx];
                parents[fx]=fy;
                return;
            }
            if(parents[fx]<parents[fy]){
                //parents[fx]-=parents[fy];
                parents[fy]=fx;
                return;
            }
            parents[fx]--;            
            parents[fy]=fx;
            return;
        }
};
class Solution {
    public:
        vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
            Union onion(c+1);
            //cout<<connections.size()<<endl;
            for(vector<int> connect:connections){
                //cout<<1<<endl;
                onion.uu(connect[0],connect[1]);
            }
            vector<bool>online(c+1,true);
            vector<int>offlineCounts(c+1,0);
            unordered_map<int,int>minimumOnlineStations;
            for(auto q:queries){
                int op=q[0],x=q[1];
                if(op==2){
                    online[x]=false;
                    offlineCounts[x]++;
                }
            }
            for(int i=1;i<=c;i++){
                int root=onion.find(i);
                if(!minimumOnlineStations.count(root)){
                    minimumOnlineStations[root]=-1;
                }

                int station=minimumOnlineStations[root];
                if(online[i]){
                    if(station==-1||station>i){
                        minimumOnlineStations[root]=i;
                    }
                }
            }
            vector<int>ans;
            for(int i=(int)queries.size()-1;i>=0;i--){
                int op=queries[i][0],x=queries[i][1];
                int root=onion.find(x);
                int station=minimumOnlineStations[root];
                if(op==1){
                    if(online[x]){
                        ans.push_back(x);
                    }
                    else{
                        ans.push_back(station);
                    }
                }
                if(op==2){
                    if(offlineCounts[x]>1){
                        offlineCounts[x]--;
                    }
                    else{
                        online[x]=true;
                        if(station==-1||station>x){
                            minimumOnlineStations[root]=x;
                        }
                    }
                }
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };