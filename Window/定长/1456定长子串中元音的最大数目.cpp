#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int res=0;
        int n=s.size();
        vector<char>y={'a','e','i','o','u'};
        set<char>v(y.begin(),y.end());
        for(int i=0;i<n;i++){
            if(v.count(s[i]))res++;
            int l=i-k+1;
            if(l<0)continue;
            ans=max(ans,res);
            if(v.count(s[l]))res--;
        }
        return ans;
    }
}; 