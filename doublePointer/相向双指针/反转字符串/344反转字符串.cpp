#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        char temp=0;
        while(l<r){
            temp=s[l];
            s[l]=s[r];
            s[r]=temp;
            l++;
            r--;
        }
        return ;
    }
};