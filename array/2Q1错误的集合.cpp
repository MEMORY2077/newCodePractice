#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> findErrorNums(vector<int>& nums) {
            set<int>hav;
            int n=nums.size();
            vector<int>ans(2,0);
            for(int i=0;i<n;i++){
                if(hav.find(nums[i])!=hav.end()){
                    ans[0]=nums[i];
                }
                hav.emplace(nums[i]);
            }
            for(int i=1;i<=n;i++){
                if(hav.find(i)==hav.end()){
                    ans[1]=i;
                    return ans;
                }
            }
            return {};
        }
    };