#include <vector>
#include <unordered_set>
using std::vector,std::unordered_set,std::pair;
class Solution {
    public:
        int maximalNetworkRank(int n, vector<vector<int>>& roads) {
            vector<int>connect(n,0);
            vector<vector<bool>>amap(n,vector<bool>(n,false));
            for(auto road:roads){
                connect[road[0]]++;
                connect[road[1]]++;
                amap[road[0]][road[1]]=amap[road[1]][road[0]]=true;
            }
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int all=connect[i]+connect[j];
                    if(amap[i][j])all--;
                    ans=std::max(ans,all);
                }
            }
            return ans;
        }
    };