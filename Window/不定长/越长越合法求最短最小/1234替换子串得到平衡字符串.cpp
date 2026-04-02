#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int balancedString(string s) {
        vector<int>cnt('X',0);
        for(char i:s){
            cnt[i]++;
        }
        int n=s.size();
        int m=n/4;
        if(cnt['Q']==cnt['W']==cnt['E']==cnt['R']==m){
            return 0;
        }
        int l=0;
        int ans=0x3f3f3f3f;
        for(int i=0;i<n;i++){
            cnt[s[i]]--;
            while(cnt['Q']<=m&&cnt['W']<=m&&cnt['E']<=m&&cnt['R']<=m){
                ans=min(ans,i-l+1);
                cnt[s[l]]++;
                l++;
            }
        }
        return ans;
    }
};