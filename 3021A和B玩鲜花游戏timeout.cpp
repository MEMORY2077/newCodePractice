#include <iostream>
using namespace std;
class Solution {
    public:
        long long flowerGame(int n, int m) {
            long long int ans;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if((i+j)%2==1){
                        ans++;
                    }
                }
            }
            return ans;
        }
    };