#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        int res=0;
        int n=s.length();
        int l=0;
        for(int i=0;i<n;i++){
            res+=abs(s[i]-t[i]);
            while(res>maxCost){
                res-=abs(s[l]-t[l]);
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};