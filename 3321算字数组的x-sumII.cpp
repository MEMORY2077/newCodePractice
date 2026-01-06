#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        using pii=pair<int,int>;
        set<pii>L,R;
        unordered_map<int,int>cnt;
        void add(int x){
            pii p={cnt[x],x};
            if(p.first==0)return;
            if(!L.empty()&&p>*L.begin()){
                sum_l+=(long long)p.first*p.second;
                L.insert(p);
            }
            else{
                R.insert(p);
            }
            return;
        }
        void del(int x){
            pii p={cnt[x],x};
            if(p.first==0)return;
            auto it=L.find(p);
            if(it!=L.end()){
                sum_l-=(long long)p.first*p.second;
                L.erase(p);
            }
            else{
                R.erase(p);
            }
            return;
        }
        void l2r(){
            pii p=*L.begin();
            sum_l-=(long long)p.first*p.second;
            L.erase(p);
            R.insert(p);
        };
        void r2l(){
            pii p=*R.rbegin();
            sum_l+=(long long)p.first*p.second;
            R.erase(p);
            L.insert(p);
            return;
        }
        vector<long long> findXSum(vector<int>& nums, int k, int x) {
            //using pii=pair<int,int>;
            //unordered_map<int,int>cnt;
            int n=nums.size();
            vector<long long>ans(n-k+1);
            for(int i=0;i<n;i++){
                int in=nums[i];
                del(in);
                cnt[in]++;
                add(in);
                int l=i+1-k;
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
                cnt[out]--;
                add(out);
            }   
            return ans;
        }
        long long sum_l=0;
    };