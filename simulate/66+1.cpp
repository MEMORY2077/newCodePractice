#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int c=1;
            int n=digits.size();
            for(int i=n-1;i>=0;i--){
                if(c==0)return digits;
                digits[i]+=c;
                c=0;
                if(digits[i]>=10){
                    c=1;
                    digits[i]%=10;
                }
            }
            if(c!=0)digits.insert(digits.begin(),c);
            return digits;
        }
    };