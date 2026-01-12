#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumOneBitOperations(int n) {
            if(n==0){
                return 0;
            }
            int k=bit_width((uint32_t) n);
            return (1<<k)-1-minimumOneBitOperations(n-(1<<(k-1)));
        }
    };