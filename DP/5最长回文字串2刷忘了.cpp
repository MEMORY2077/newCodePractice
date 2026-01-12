#include <vector>
#include<iostream>
#include <string>
using namespace std;
class Solution {
    public:
        string longestPalindrome(string s) {
            string ans=s.substr(0,1);
            int n=s.size();
            if(n==1)return ans;
            vector<vector<bool>>dp(n,vector<bool>(n,0));
            for(int i=0;i<n;i++){
                dp[i][i]=true;
            }
            for(int l=2;l<=n;l++){
                for(int i=0;i<n;i++){
                    int j=i+l-1;
                    if(j<n&&s[i]==s[j]){
                        if(l<3){
                            dp[i][j]=true;
                        }
                        else{
                            dp[i][j]=dp[i+1][j-1];
                        }
                        if(dp[i][j]&&l>ans.size()){
                            ans=s.substr(i,l);
                        }
                    }
                }
            }
            return ans;
        }
    };
    int main(void){
        Solution a;
        std::cout<<a.longestPalindrome("aacabdkacaa");
        return 0;
    }