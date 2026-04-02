#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        string ans(n+m-1,0);
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=0;j<m;j++){
                    if(ans[i+j]&&ans[i+j]!=str2[j])return "";
                    ans[i+j]=str2[j];
                }
            }
        }
        string old_ans=ans;
        for(int i=0;i<n+m-1;i++){
            if(ans[i]==0)ans[i]='a';
        }
        for(int i=0;i<n;i++){
            if(str1[i]=='T')continue;
            bool same=false;
            if(ans.substr(i,m)==str2){
                same=true;
                for(int j=m-1;j>=0;j--){
                    if(old_ans[i+j]==0){
                        ans[i+j]='b';
                        same=false;
                        break;
                    }
                }
                if(same)return "";
            }
        }
        return ans;
    }
};