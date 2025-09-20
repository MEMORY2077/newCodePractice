#include <iostream>
#include <vector>
#include <math.h>
//取模后不能直接相除
using namespace std;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD=1000000007;
        vector<int>barray;
        int now=1;
        while(n!=0){
            if(n%2==1){
                barray.push_back(now);
            }
            n/=2;
            now*=2;
        }
        int m=barray.size();
        vector<vector<int>>res(m,vector<int>(m,0));
        for(int i=0;i<m;i++){
            res[i][i]=barray[i];
            for(int j=i+1;j<m;j++){
                res[i][j]=1LL*res[i][j-1]*barray[j]%MOD;
            }
        }
        vector<int>ans;
        ans.reserve(queries.size());
        for(auto q:queries){
            ans.push_back(res[q[0]][q[1]]);
        }
        return ans;
    }
};
//1 4 8