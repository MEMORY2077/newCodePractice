#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numSteps(string s) {
        int ans=s.size()-1;
        int carry=0;
        for(int i=s.size()-1;i>0;i--){
            int sum=s[i]-'0'+carry;
            ans+=sum%2;
            carry=(sum+sum%2)/2;
        }
        return ans+carry;
    }
};