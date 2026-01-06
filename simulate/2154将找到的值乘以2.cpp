#include <vector>
#include <set>
using namespace std;
class Solution {
    public:
        int findFinalValue(vector<int>& nums, int original) {
            set<int>n(nums.begin(),nums.end());
            while(1){
                if(n.find(original)==n.end()){
                    return original;
                }
                original*=2;
            }
            return -1;
        }
    };