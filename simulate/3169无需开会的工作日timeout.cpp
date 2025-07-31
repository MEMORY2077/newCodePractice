#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<int>canlander(days+1,0);
        for(auto i:meetings){
            for(int j=i[0];j<=i[1]&&j<=days;j++){
                if(canlander[j]==0){
                    canlander[j]=1;
                }
            }
        }
        int count=0;
        for(int i=1;i<=days;i++){
            if(canlander[i]==0)count++;
        }
        return count;
    }
};