#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int last=-k-1;
        int n=nums.size();
        for(int i=k-1;i>=0;i--){
            if(nums[i]==key){
                last=i;
                break;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i+k<n&&nums[i+k]==key)last=i+k;
            if(last>=i-k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};