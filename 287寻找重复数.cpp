#include <vector>
using namespace std;
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            //这题居然是链表判环，道心破碎了
            int n=nums.size();
            int slow=0;
            int fast=0;
            do{
                slow=nums[slow];
                fast=nums[nums[fast]];
            }while(slow!=fast);
            slow=0;
            while(slow!=fast){
                slow=nums[slow];
                fast=nums[fast];
            }
            return slow;
        }
    };