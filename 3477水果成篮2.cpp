#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool>use(baskets.size(),false);
        int ans=0;
        int n=baskets.size();
        for(auto fruit:fruits){
            int i=0;
            for(i=0;i<n;i++){
                if(baskets[i]>=fruit&&!use[i]){
                    ans++;
                    use[i]=true;
                    break;
                }
            }
        }
        return n-ans;
    }
};