#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int i=0;
        for (i=0;i<n;i++){
            if (s[i]=='0')break;
        }
        if (i==n-1)return true;
        for (i;i<n;i++)
        {
            if (s[i]=='1')return false;
        }
        return true;
    }
};