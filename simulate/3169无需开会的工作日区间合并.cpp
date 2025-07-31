#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    static bool us2sort(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>>canlander;
        sort(meetings.begin(),meetings.end(),us2sort);
        for(auto now:meetings){
            if(!canlander.empty()&&canlander.back()[1]>=now[0]){
                canlander.back()[1]=max(canlander.back()[1],now[1]);
            }
            else {
                canlander.push_back(now);
            }
        }
        int count=0;
        for(auto now:canlander){
            count+=(now[1]-now[0]+1);
        }
        return days-count;
    }
};