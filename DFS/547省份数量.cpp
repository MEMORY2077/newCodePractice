#include <vector>
using namespace std;
class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n=isConnected.size();
            visited=vector<int>(n,0);
            int ans=0;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    ans++;
                    dfs(isConnected,i);
                }
            }
            return ans;
        }   
        void dfs(vector<vector<int>>&isConnected,int now){
            visited[now]=1;
            int n=isConnected[now].size();
            for(int i=0;i<n;i++){
                if(isConnected[now][i]==1&&visited[i]==0&&now!=i){
                    dfs(isConnected,i);
                }
            }
            return;
        }
    private:
        vector<int>visited;
    };