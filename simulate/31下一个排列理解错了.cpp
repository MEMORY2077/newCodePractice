#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            vector<int>part=nums;
            sort(part.begin(),part.end());
            int n=part.size();
            unordered_map<int,int>index;
            for(int i=0;i<n;i++){
                index.emplace(part[i],i);
            }
            int add=1;
            for(int i=n-1;i>=0;i--){
                int in=index[nums[i]];
                in+=add;
                add=0;
                if(in==n){
                    add=1;
                    in%=n;
                }
                nums[i]=part[in];
            }
            return ;
        }
    };