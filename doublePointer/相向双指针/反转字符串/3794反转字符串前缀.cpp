#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string reversePrefix(string s, int k) {
        char temp;
        for(int l=0,r=k-1;l<r;l++,r--){
            temp=s[l];
            s[l]=s[r];
            s[r]=temp;
        }
        return s;
    }
};