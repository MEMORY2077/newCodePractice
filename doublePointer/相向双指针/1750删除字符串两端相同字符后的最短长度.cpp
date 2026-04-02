#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        while(1){
            if(l>=r||s[l]!=s[r])break;
            while(l<n-1&&s[l]==s[l+1])l++;
            while(r>0&&s[r-1]==s[r])r--;
            l++;
            r--;
        }
        return max(r-l+1,0);
    }
};