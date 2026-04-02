#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i][i]=='0')ans.push_back('1');
            else ans.push_back('0');
        }
        return ans;
    }
};