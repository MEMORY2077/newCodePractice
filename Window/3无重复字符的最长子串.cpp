#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=0;
        unordered_set<char>map;
        while(r<s.size()){
            if(map.find(s[r])!=map.end()){
                map.emplace(s[r]);
                r++;
            }
            else{
                map.erase(s[l]);
                l++;
            }
            ans=max(ans,(r-l+1));
        }
        return ans;
    }
};