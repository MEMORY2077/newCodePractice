#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int>cnt;
            int maxcnt=0;
            for(int i:nums){
                cnt[i]++;
                maxcnt=max(cnt[i],maxcnt);
            }
            vector<vector<int>>basket(maxcnt+1);
            for(auto&[x,c]:cnt){
                basket[c].push_back(x);
            }
            vector<int>ans;
            for(int i=maxcnt;i>=0&&ans.size()<k;i--){
                ans.insert(ans.end(),basket[i].begin(),basket[i].end());
            }
            return ans;
        }
    };