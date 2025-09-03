#include <iostream>
using namespace std;
class Solution {
    public:
        long long flowerGame(int n, int m) {
            long long int ans;
            long long int no,nd,mo,md;
            no=n/2;
            nd=n/2;
            mo=m/2;
            md=m/2;
            if(n%2==1)no++;
            if(m%2==1)mo++;
            ans=no*md+mo*nd;
            return ans;
        }
    };