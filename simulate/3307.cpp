#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        //可以，但是会越界
        long long ans=0;
        long long step=operations.size();
        long long length=pow(2,step);
        while(step>0){
            length>>=1;
            if(k>length){
                ans+=operations[step-1];
                k-=length;
            }
            step--;
        }
        return 'a'+(ans%26);
    }
};