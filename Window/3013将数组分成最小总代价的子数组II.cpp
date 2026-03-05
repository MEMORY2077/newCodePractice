#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    long long sum=0;
    void L2R(multiset<int>L,multiset<int>R){
        int x=*L.rbegin();
        sum-=x;
        L.erase(L.find(x));
        R.insert(x);
    }
    void R2L(multiset<int>L,multiset<int>R){
        int x=*R.begin();
        sum+=x;
        R.erase(R.find(x));
        L.insert(x);
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        k--;
        for(int i=0;i<dist+2;i++){
            sum+=nums[i];
        }
        multiset<int>L(nums.begin()+1,nums.begin()+dist+2),R;
        while(L.size()>k){
            L2R(L,R);
        }
        long long ans=sum;
        for(int i=dist+2;i<nums.size();i++){
            int out=nums[i-dist-1];
            auto it = L.find(out);
            if(it!=L.end()){
                sum-=out;
                L.erase(it);
            }
            else{
                R.erase(R.find(out));
            }
            int in=nums[i];
            if(in<*L.rbegin()){
                sum+=in;
                L.insert(in);
            }
            else{
                R.insert(in);
            }
            if(L.size()==k-1){
                R2L(L,R);
            }
            else if(L.size()==k+1){
                L2R(L,R);
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};