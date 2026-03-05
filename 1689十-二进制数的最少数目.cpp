#include<vector>
#include <string>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        char ans=0;
        for(char now:n){
            ans=max(ans,now);
        }
        return ans-'0';
    }
};