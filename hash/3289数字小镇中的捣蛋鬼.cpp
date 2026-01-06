#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mm;
        vector<int>ans;
        for(int num:nums){
            if(++mm[num]==2){
                ans.push_back(num);
                if(ans.size()==2)return ans;
            }
        }
        return {};
    }
};