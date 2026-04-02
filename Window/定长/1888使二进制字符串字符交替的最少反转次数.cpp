#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int ans=n;
        int res=0;
        for(int i=0;i<n*2-1;i++){
            if(s[i%n]%2!=i%2)res++;
            int l=i-n+1;
            if(l<0)continue;
            ans=min({ans,res,n-res});
            if(s[l]%2!=l%2)res--;
        }
        return ans;
    }
};