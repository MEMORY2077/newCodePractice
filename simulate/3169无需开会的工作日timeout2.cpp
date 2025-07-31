#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        unordered_map<int,int>canlander;
        for(auto i:meetings){
            for(int j=i[0];j<=i[1]&&j<=days;j++){
                canlander[j]++;
            }
        }
        int count=days-canlander.size();
        return count;
    }
};