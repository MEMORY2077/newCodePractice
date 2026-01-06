#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int empty=0;
        do{ 
            ans+=numBottles;
            empty+=numBottles;
            numBottles=empty/numExchange;
            empty%=numExchange;
        }while(empty>numExchange);
        return ans+numBottles;
    }
};
int main(void){
    Solution a;
    a.numWaterBottles(9,3);
    return 0;
}