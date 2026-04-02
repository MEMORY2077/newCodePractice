#include <bit>
#include <math.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int m=__bit_width(n);
        return ((1<<m)-1)^n;
    }
};