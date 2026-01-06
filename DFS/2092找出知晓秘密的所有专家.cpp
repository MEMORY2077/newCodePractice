#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
private:
    static bool us2sort(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),us2sort);
        unordered_set<int>know={0,firstPerson};
        int m=meetings.size();
        for(int i=0;i<m;){
            unordered_map<int,vector<int>>g;
            int time=meetings[i][2];
            for(;i<m&&meetings[i][2]==time;i++){//建图
                int x=meetings[i][0],y=meetings[i][1];
                g[x].push_back(y);
                g[y].push_back(x);
            }
            unordered_set<int>vis;//避免重复访问
            for(auto&[x,_]:g){
                if(know.count(x)&&!vis.count(x)){
                    dfs(x,vis,know,g);
                }
            }
        }
        return vector<int>(know.begin(),know.end());
    }
    void dfs(int x,unordered_set<int>&vis,unordered_set<int>&know,unordered_map<int,vector<int>>&g){
        vis.insert(x);
        know.insert(x);
        for(int y:g[x]){
            if(!vis.count(y)){
                dfs(y,vis,know,g);
            }
        }
    }
};