#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            sort(potions.begin(),potions.end());
            int n=spells.size();
            int m=potions.size();
            vector<int>ans(n,0);
            for(int i=0;i<n;i++){
                int target=success/spells[i];
                int left=0;
                int right=m;
                int where=0x3f3f3f3f;
                while(left<=right){
                    int mid=(right-left)/2+left;
                    if((long long)potions[mid]*spells[i]>=success){
                        where=mid;
                        right=mid-1;
                    }
                    else{
                        left=mid+1;
                    }
                }
                if(where<m){
                    ans[i]=m-where;
                }
                else ans[i]=0;
            }
            return ans;
        }
    };