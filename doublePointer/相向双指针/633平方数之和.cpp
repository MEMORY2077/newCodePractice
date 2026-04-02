#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int n=int(sqrt(c));
        int l=0;
        int r=n;
        while(l<=r){
            long long int x=1LL*l*l+1LL*r*r;
            if(x<c)l++;
            else if(x>c)r--;
            else return true;
        }
        return false;
    }
};