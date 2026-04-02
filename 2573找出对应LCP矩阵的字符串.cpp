#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans(n,0);
        int i=0;
        for(char c='a';c<='z';c++){
            for(int j=i;j<n;j++){
                if(lcp[i][j])ans[j]=c;
            }
            while(i<n&&ans[i])i++;
            if(i>=n)break;
        }
        for(int i=0;i<n;i++){
            if(!ans[i])return "";
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int real;
                if(ans[i]!=ans[j])real=0;
                else if(i==n-1||j==n-1)real=1;
                else real=lcp[i+1][j+1]+1;
                if(lcp[i][j]!=real)return "";
            }
        }
        return ans;
    }
};