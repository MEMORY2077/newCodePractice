//打擂台
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        int hp=0;
        for(int now:nums){
            if(hp==0){
                ans=now;
                hp=1;
            }
            else{
                if(now==ans)hp++;
                else hp--;
            }
        }
        return ans;
    }
};