#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
//其实就是判断环，有环的就不安全，没环的就安全
//不要在dfs里面加点，这样不好判断重复，就会用哈希，而且也不好确定顺序，导致需要排序，超时
class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n=graph.size();
            visited=vector<int>(n,0);
            vector<int>result;                
            for(int i=0;i<n;i++){
                if(dfs(graph,i)){
                    result.push_back(i);
                }
            }
            //for(int i:ans){
            //    result.push_back(i);
            //}
            //sort(result.begin(),result.end());
            return result;
        }
        bool dfs(vector<vector<int>>&graph,int now){
            if(visited[now]==2)return false;
            if(visited[now]==1)return true;
            //if(graph[now].empty()){
            //    ans.emplace(now);
            //    return true;
            //}
            visited[now]=2;
            int n=graph[now].size();
            for(int i=0;i<n;i++){
                if(!dfs(graph,graph[now][i])){
                    return false;
                }
            }
            visited[now]=1;
            return true;
        }
        unordered_set<int>ans;
        vector<int>visited;
    };