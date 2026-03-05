using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int t1=0x55555555;
        unsigned int t2=0xbbbbbbbb;
        if(((n&t1)==0)||((n&t2)==0))return true;
        return false;
    }
};