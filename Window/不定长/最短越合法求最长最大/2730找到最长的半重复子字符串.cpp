#include<vector>
#include<string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int cnt=0;
        //int res=1;
        int ans=0;
        int n=s.size();
        int l=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])cnt++;
            while(cnt>1){
                if(l<n-1&&s[l]==s[l+1])cnt--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};