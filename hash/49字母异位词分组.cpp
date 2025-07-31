#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        for(auto now:strs){
            string key=now;
            sort(key.begin(),key.end());
            map[key].push_back(now);
        }
        vector<vector<string>>ans;
        for(auto i:map){
            ans.push_back(i.second);
        }
        return ans;
    }
};