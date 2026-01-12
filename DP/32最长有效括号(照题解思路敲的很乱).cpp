#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        int longestValidParentheses(string s) {
            vector<int>dp(s.size(),0);
            int n=s.size();
            for(int i=0;i<n;i++){
                if(s[i]=='('){
                    dp[i]=0;
                    continue;
                }
                if(i>1&&s[i]==')'){
                    if(s[i-1]=='('){
                        if(i>=2){
                            dp[i]=dp[i-2]+2;
                        }
                        else dp[i]=2;
                    }
                    if(s[i-1]==')'){
                        if(i>=2){
                            if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                                if(i-dp[i-1]-2>=0){
                                    dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
                                }
                                else dp[i]=dp[i-1]+dp[0]+2;
                            }
                        }
                    }
                }
            }
            int maximum=0;
            for(int i=0;i<n;i++){
                maximum=max(maximum,dp[i]);
            }
            return maximum;
        }
    };