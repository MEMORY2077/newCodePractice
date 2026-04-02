#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<unordered_map<char,int>>mp(2,unordered_map<char,int>());
        int n=s1.size();
        for(int i=0;i<n;i++){
            mp[i%2][s1[i]]++;
            mp[i%2][s2[i]]--;
            if(mp[i%2][s1[i]]==0)mp[i%2].erase(s1[i]);
            if(mp[i%2][s2[i]]==0)mp[i%2].erase(s2[i]);
        }
        if(mp[0].size()==0&&mp[1].size()==0)return true;
        return false;
    }
};