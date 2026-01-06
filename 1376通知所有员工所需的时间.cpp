#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    //深度优先遍历，计算最晚收到通知的员工什么时候才能收到通知
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++){
            tree[manager[i]].push_back(i);
        }
        int maxtime=dfs(n,headID,informTime);
        return maxtime;
    }
    int dfs(int n,int nowID,vector<int>&informTime){
        int maxtime=0;
        for(int i:tree[nowID]){
            maxtime=max(maxtime,dfs(n,i,informTime));
        }
        return maxtime+informTime[nowID];
    }
    unordered_map<int,vector<int>>tree;
};