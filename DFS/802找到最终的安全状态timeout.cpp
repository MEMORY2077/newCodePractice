#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n=graph.size();
            visited=vector<int>(n,0);            
            for(int i=0;i<n;i++){
                if(visited[i]==0)dfs(graph,i);
            }
            vector<int>result;    
            for(int i:ans){
                result.push_back(i);
            }
            sort(result.begin(),result.end());
            return result;
        }
        bool dfs(vector<vector<int>>&graph,int now){
            if(visited[now]==2)return false;
            if(graph[now].empty()){
                ans.emplace(now);
                return true;
            }
            visited[now]=2;
            int n=graph[now].size();
            int count=0;
            for(int i=0;i<n;i++){
                if(visited[graph[now][i]]!=2&&dfs(graph,graph[now][i])){
                    count++;
                }
            }
            visited[now]=1;
            if(count==n){
                ans.emplace(now);
                return true;
            }
            return false;
        }
        unordered_set<int>ans;
        vector<int>visited;
    };