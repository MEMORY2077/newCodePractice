#include <vector>
using std::vector;
class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            vector<vector<bool>>amap(n+1,vector<bool>(n+1,false));
            for(auto tru:trust){
                amap[tru[0]][tru[1]]=true;
            }
            for(int i=1;i<=n;i++){
                bool flag=true;
                for(int j=1;j<=n;j++){
                    if(amap[i][j]==true||(amap[j][i]==false&&i!=j)){
                        flag=false;
                        break;
                    }
                }
                if(flag)return i;
            }
            return -1;
        }
    };