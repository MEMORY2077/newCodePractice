#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long a=numerator;
        long long b=denominator;
        string ans;
        if(a*b<0)ans="-";
        a=abs(a);
        b=abs(b);
        long long q=a/b;
        long long r=a%b;
        if(r==0){
            return ans+to_string(q);
        }
        ans+=to_string(q);
        ans+='.';
        unordered_map<long long,int>r2pos={{r,ans.size()}};
        while(r){
            r*=10;
            q=r/b;
            r=r%b;
            ans+='0'+q;
            if(r2pos.find(r)!=r2pos.end()){
                int pos=r2pos[r];
                return ans.substr(0,pos)+"("+ans.substr(pos)+")";
            }
            r2pos[r]=ans.size();
        }
        return ans;
    }
};