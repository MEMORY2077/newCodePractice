#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        unordered_set<char>y={'a','e','i','o','u'};
        int n=s.size();
        int cnt=0;
        int i=0;
        for(i=0;i<n&&s[i]!=' ';i++){
            if(y.count(s[i]))cnt++;
        }
        int cnt2=0;
        int l=i+1;
        for(i;i<n;i++){
            if(y.count(s[i]))cnt2++;
            if(s[i]==' '){
                if(cnt2==cnt){
                    reverse(s.begin()+l,s.begin()+i);
                }
                l=i+1;
                cnt2=0;
            }
        }
        if(cnt2==cnt)reverse(s.begin()+l,s.end());
        return s;
    }
};