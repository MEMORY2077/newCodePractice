#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        using pii=pair<int,int>;
        unordered_map<int,int>cnt;
        set<pii>L,R;
        int sum_l=0;
        void add(int x){
            pii p={cnt[x],x};
            if(p.first==0)return;
            if(!L.empty()&&p>*L.begin()){
                L.insert(p);
                sum_l+=p.first*p.second;
            }
            else{
                R.insert(p);
            }
        };
        void del(int x){
            pii p={cnt[x],x};
            if(p.first==0)return;
            auto it=L.find(p);
            if(it!=L.end()){
                L.erase(p);
                sum_l-=p.first*p.second;
            }
            else {
                R.erase(p);
            }
        };
        void l2r(){
            pii p=*L.begin();
            sum_l-=p.first*p.second;
            L.erase(p);
            R.insert(p);
        };
        void r2l(){
            pii p=*R.rbegin();
            sum_l+=p.first*p.second;
            R.erase(p);
            L.insert(p);
        }
        vector<int> findXSum(vector<int>& nums, int k, int x) {
            int n=nums.size();
            vector<int>ans(n+1-k);
            for(int r=0;r<n;r++){
                int in=nums[r];
                del(in);
                cnt[r]++;
                add(in);
                int l=r+1-k;
                if(l<0)continue;
                while(!R.empty()&&L.size()<x){
                    r2l();
                }
                while(L.size()>x){
                    l2r();
                }
                ans[l]=sum_l;
                int out=nums[l];
                del(out);
                cnt[l]--;
                add(out);
            }
            return ans;
        }
    };