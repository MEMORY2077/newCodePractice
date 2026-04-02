#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans;
        int n=s.size();
        int l=0;
        while(l<n){
            while(l<n&&s[l]==' ')l++;
            if(l>=n)break;
            int r=l;
            while(r<n&&s[r]!=' ')r++;
            reverse(s.begin()+l,s.begin()+r);
            ans+=s.substr(l,r-l);
            ans.push_back(' ');
            l=r;
        }
        ans.pop_back();
        return ans;
    }
};