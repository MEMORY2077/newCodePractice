#include <vector>
#include <array>
using namespace std;
class Solution {
    private:
        vector<vector<int>>g;
        int budget;
        vector<int>present;
        vector<int>future;
    public:
        int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
            g=vector<vector<int>>(n);
            this->budget=budget;
            this->present=present;
            this->future=future;
            for(auto&e:hierarchy){
                g[e[0]-1].push_back(e[1]-1);
            }
            return dfs(0)[budget][0];
        }
        vector<array<int,2>> dfs(int x){
            vector<array<int,2>>sub_f(budget+1);
            for(int y:g[x]){
                auto fy=dfs(y);
                for(int j=budget;j>=0;j--){
                    //枚举子树y的预算为jy
                    //体积为jy，价值为fy[jy][k]
                    for(int jy=0;jy<=j;jy++){
                        for(int k=0;k<2;k++){
                            //k=0不买x，k=1买x
                            for(int k=0;k<2;k++){
                                sub_f[j][k]=max(sub_f[j][k],sub_f[j-jy][k]+fy[jy][k]);
                            }
                        }
                    }
                }
            }
            vector<array<int,2>>f(budget+1);
            for(int j=0;j<=budget;j++){
            for(int k=0;k<2;k++){
                    int cost=present[x]/(k+1);
                    if(j>=cost){
                        //不买x，转移来源是sub_f[j][0]
                        //买x，转移来源是sub_f[j-cost][1]，对于子树来说，父节点一定买
                        f[j][k]=max(sub_f[j][0],sub_f[j-cost][1]+future[x]-cost);
                    }
                    else{//只能不买x
                        f[j][k]=sub_f[j][0];
                    }
                }
            }
            return f;
        }
    };