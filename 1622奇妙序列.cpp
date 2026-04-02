#include <vector>
#include <math.h>
//懒运算，想到了但是懒得往下想了。。。66666
using namespace std;
class Fancy {
public:
    long long pow(long long x,int n){
        long long res=1;
        for(;n;n/=2){
            if(n%2){
                res=res*x%MOD;
            }
            x=x*x%MOD;
        }
        return res;
    }
    Fancy() {
        
    }
    void append(int val) {
        long long x=(val-add+MOD)*pow(mul,MOD-2)%MOD;
        f.push_back(x);
    }
    void addAll(int inc) {
        add+=inc;
    }
    void multAll(int m) {
        add*=m;
        mul*=m;
    }
    int getIndex(int idx) {
        if(idx>=f.size())return -1;
        return (f[idx]*mul+add)%MOD;
    }
private:
    const int MOD=1000000007;
    vector<long long int>f;
    long long add=0;
    long long mul=1;
};
