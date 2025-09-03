#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minPrices=INT_MAX;
            int maxPro=0;
            for(int now:prices){
                if(now<minPrices){
                    minPrices=now;
                    continue;
                }
                maxPro=max(maxPro,now-minPrices);
            }
            return maxPro;
        }
};
