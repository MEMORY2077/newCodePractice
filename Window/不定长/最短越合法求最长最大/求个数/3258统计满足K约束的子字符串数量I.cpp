#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        vector<int>cnt(2,0);
        int l=0;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            cnt[s[i]-'0']++;
            while(cnt[0]>k&&cnt[1]>k){//题里说的满足任意条件即可，俩都不符合才缩
                cnt[s[l]-'0']--;
                l++;
            }
            ans+=(i-l+1);
        }
        return ans;
    }
};