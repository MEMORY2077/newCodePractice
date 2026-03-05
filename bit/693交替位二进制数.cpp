using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int  x=(n>>1)^n;
        return ((x+1)&x)==0;
    }
};