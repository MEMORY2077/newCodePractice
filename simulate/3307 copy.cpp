#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        int m=log2(k)+1;
        int ans=0;
        for(int i=m-1;i>=0;i++){
            if(k>>i&1){
                ans+=operations[i];
            }
        }
        return 'a'+(ans%26);
    }
};