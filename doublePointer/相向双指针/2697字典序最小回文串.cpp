#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        for(int l=0,r=n-1;l<r;l++,r--){
            if(s[l]!=s[r]){
                if(s[l]<s[r])s[r]=s[l];
                else s[l]=s[r];
            }
        }
        return s;
    }
};