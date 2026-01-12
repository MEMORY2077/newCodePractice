#include <vector>
#include <queue>
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
            vector<int>online(c+1,1);
            vector<int>ans;
            vector<priority_queue<int,vector<int>,greater<int>>>f(c+1);
            for(int i=1;i<c+1;i++){
                int fi=onion.find(i);
                for(int j=i+1;j<c+1;j++){
                    int fj=onion.find(j);
                    if(fi==fj&&fj>0){
                        f[i].emplace(j);
                        f[j].emplace(i);
                    }
                }
            }
            for(auto query:queries){
                if(query[0]==1){//检修
                    if(online[query[1]]==1)ans.push_back(query[1]);
                    else{
                        if(!f[query[1]].empty()){
                            while(!f[query[1]].empty()){
                                int now=f[query[1]].top();
                                if(online[now]==1){
                                    ans.push_back(now);
                                    break;
                                }
                                else{
                                    f[query[1]].pop();
                                }
                            }
                            if(f[query[1]].empty())ans.push_back(-1);
                        }    
                        else ans.push_back(-1);
                    }
                }
                else{//离线
                    online[query[1]]=0;
                }
            }
            return ans;
        }
    };