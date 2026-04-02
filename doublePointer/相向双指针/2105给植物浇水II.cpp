#include <vector>
using namespace std;
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int cntA=0;
        int cntB=0;
        int lastA=capacityA;
        int lastB=capacityB;
        int n=plants.size();
        int i,j;
        for(i=0,j=n-1;i<j;i++,j--){
            if(lastA>=plants[i])lastA-=plants[i];
            else{
                cntA++;
                lastA=(capacityA-plants[i]);
            }
            if(lastB>=plants[j])lastB-=plants[j];
            else{
                cntB++;
                lastB=(capacityB-plants[j]);
            }
        }
        if(i==j){
            if(lastA<lastB){
                if(lastB<plants[i])cntB++;
            }
            else{
                if(lastA<plants[i])cntA++;
            }
        }
        return cntA+cntB;
    }
};