#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
            int maxS=0;
            int maxDi=0;
            for(vector<int>now:dimensions){
                int nowDi=now[0]*now[0]+now[1]*now[1];
                if(nowDi>maxDi){
                    maxS=now[0]*now[1];
                    maxDi=nowDi;
                }
                else if(nowDi==maxDi){
                    int nowS=now[0]*now[1];
                    if(nowS>maxS){
                        maxS=nowS;
                        maxDi=nowDi;
                    }
                }
            }
            return maxS;
        }
    };