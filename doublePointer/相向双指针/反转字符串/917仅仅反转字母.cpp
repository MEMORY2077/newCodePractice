#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        while(1){
            while(l<r&&!isalpha(s[l]))l++;
            while(r>l&&!isalpha(s[r]))r--;
            if(l>=r)break;
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};