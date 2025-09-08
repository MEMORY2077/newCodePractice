#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        string longestPalindrome(string s) {
            if(s.size()==1)return s;
            string ans;
            int n=s.size();
            vector<vector<bool>>dp(n,vector<bool>(n,false));
            for(int i=0;i<n;i++){
                dp[i][i]=true;
            }
            for(int l=2;l<=n;l++){
                for(int i=0;i<n;i++){
                    int j=i+l-1;
                    if(j<n){
                        if(s[i]==s[j]){
                            if(l<3)dp[i][j]=true;
                            else{
                                dp[i][j]=dp[i+1][j-1];
                            }
                            if(dp[i][j]&&l>ans.size()){
                                ans=s.substr(i,l);
                            }
                        }
                    }
                }
            }
            return ans;
        }
    };
int main(void){
    Solution a;
    a.longestPalindrome("babad");
    return 0;
}