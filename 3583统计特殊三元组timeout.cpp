#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    public:
        const int MOD=1000000007;
        int specialTriplets(vector<int>& nums) {
            int ans=0;
            unordered_map<int,vector<int>>hav;
            int n=nums.size();
            for(int i=0;i<n;i++){
                int numi=nums[i];
                hav[numi].push_back(i);
            }
            for(int j=0;j<n;j++){
                //cout<<"j="<<j<<endl;
                int numj=nums[j];
                int numi=numj*2;
                int l=0;
                for(int i:hav[numi]){
                    if(i<j)l++;
                    else break;
                }
                int r=hav[numi].size()-l;
                if(numi==numj)r--;
                //cout<<l<<' '<<r<<endl;
                ans=(ans+((long long)r*l)%MOD)%MOD;
            }
            return ans;
        }
    };