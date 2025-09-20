#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>=4){
            if(n%4!=0){
                return false;
            }
            n/=4;
        }
        if(n!=1&&n!=0)return false;
        return true;
    }
};