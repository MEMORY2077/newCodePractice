#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numSteps(string s) {
        unsigned long long int num=0;
        for(char a:s){
            num<<=1;
            if(a=='0'){
                num+=0;
            }
            else{
                num+=1;
            }
        }
        int ans=0;
        while(num!=1){
            if(num%2==0){
                num>>=1;
            }
            else{
                num+=1;
            }
            ans++;
        }
        return ans;
    }
};