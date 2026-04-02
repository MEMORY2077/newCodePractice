#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char>ord={'a','e','i','o','u','A','E','I','O','U'};
        int n=s.size();
        int l=0,r=n-1;
        while(1){
            while(l<r&&!ord.count(s[l]))l++;
            while(r>l&&!ord.count(s[r]))r--;
            if(l>=r)break;
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};