#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int now;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i-k+1;
            if(l<0)continue;
            now=stoi(s.substr(l,k));
            if(now!=0&&num%now==0)ans++;
        }
        return ans;
    }
};