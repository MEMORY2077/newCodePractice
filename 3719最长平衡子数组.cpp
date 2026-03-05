#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>odd;
            unordered_map<int,int>even;
            for(int j=i;j<n;j++){
                auto&c=(nums[j]&1)?odd:even;
                c[nums[j]]++;
                if(odd.size()==even.size()){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};