#include <iostream>
#include <vector>
#include <math.h>
//取模后不能直接相除
using namespace std;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>barray;
        int now=1;
        while(n!=0){
            if(n%2==1){
                barray.push_back(now);
            }
            n/=2;
            now*=2;
        }
        vector<int>pre=barray;
        for(int i=1;i<pre.size();i++){
            pre[i]=(pre[i-1]*pre[i])%1000000007;
        }
        vector<int>ans(queries.size()+1,0);
        for(int i=0;i<ans.size();i++){
            if(queries[i][0]>0)ans[i]=pre[queries[i][1]]/pre[queries[i][0]-1];
            else ans[i]=pre[queries[i][1]];
        }
        return ans;
    }
};
//1 4 8