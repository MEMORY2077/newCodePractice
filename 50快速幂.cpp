class Solution {
public:
    double myPow(double x, int N) {
        long long n =N;
        if(x==1||n==0)return 1;
        if(n<0){
            x=(1/x);
            n=1LL*(-n);
        }
        double g=x;
        double ans=1;
        //int length = log2(n);
        for(int i=0;i<64;i++){
            if(n&1==1){
                ans*=g;
            }
            g*=g;
            n>>=1;
        }
        return ans;
    }
};