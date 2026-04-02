#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        string now;
        int ans=0;
        map<char,int>cnt;
        int n=s.size();
        int l=0;
        for(int i=0;i<n;i++){
            cnt[s[i]]++;
            while(cnt[s[i]]>2){
                cnt[s[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};