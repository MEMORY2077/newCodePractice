#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//和2一样吧，就是多了个判断条件？
class Solution {
    public:
        vector<string>strs;
        int minDeletionSize(vector<string>& strs) {
            this->strs=strs;
            int m=strs[0].size();
            vector<int>dp(m);
            for(int i=0;i<m;i++){
                for(int j=0;j<i;j++){
                    if(dp[j]>dp[i]&&less_eq(j,i))dp[i]=dp[j];
                }
                dp[i]++;
            }
            int maximum=dp[0];
            for(int i=1;i<m;i++){
                maximum=max(maximum,dp[i]);
            }
            return m-maximum;
        }
        bool less_eq(int j,int i){
            for(auto&s:strs){
                if(s[j]>s[i]){
                    return false;
                }
            }
            return true;
        }
    };