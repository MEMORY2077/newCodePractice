#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>map;
        for(auto i:p){
            map[i]--;
        }
        vector<int>ans;
        int l=0;
        int r=0;
        int n=p.size();
        for(r;r<n;r++){
            map[r]++;
            if(map[r]==0){
                map.erase(r);
            }
        }
        if(map.empty())ans.push_back(l);
        while(r<s.size()){
            r++;
            map[r]++;
            if(map[r]==0)map.erase(r);
            map[l]--;
            if(map[l]==0)map.erase(l);
            l++;
            if(map.empty())ans.push_back(l);
        }
        return ans;
    }
};