#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int l=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                reverse(s.begin()+l,s.begin()+i);
                l=i+1;
            }
        }
        reverse(s.begin()+l,s.end());
        return s;
    }
};