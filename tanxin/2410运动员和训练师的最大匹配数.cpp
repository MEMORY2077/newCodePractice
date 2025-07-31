#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int j=0;
        int i=0;
        int count=0;
        for(i=0;i<players.size();i++){
            while(j<trainers.size()&&trainers[j]<players[i]){
                j++;
            }
            if(j<trainers.size()){
                count++;
                j++;
            }
            else break;
        }
        return i;
    }
};