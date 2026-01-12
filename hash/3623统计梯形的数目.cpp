#include<vector>
#include <unordered_map>
#include<map>
#include <set>
#include <algorithm>
//归类出每行的点
//算出每行可能的边数
//双重遍历算总数x 当前行边数*过往的所有边数v 时间复杂度从n^2变成n
using namespace std;
class Solution {
    const int MOD=1000000007;
    public:
        int countTrapezoids(vector<vector<int>>& points) {
            unordered_map<int,int>row;
            int ymax=0;
            for(auto point:points){
                row[point[1]]++;
                ymax=max(ymax,point[1]);
            }
            //int ans=0;
            map<int,int>cor;
            for(auto[y,count]:row){
                cor[y]=((long long)(count%MOD)*((count-1)%MOD))%MOD/2;   
            //    ans=(ans%MOD+(ans*cor[y])%MOD)%MOD;             
            }
            int ans=0;
            int sum=0;
            for(auto cou1=cor.begin();cou1!=cor.end();cou1++){
                ans=(ans%MOD+((long long)sum*cou1->second)%MOD)%MOD;
                sum=(sum+cou1->second)%MOD;
            }
            return ans;
        }
    };