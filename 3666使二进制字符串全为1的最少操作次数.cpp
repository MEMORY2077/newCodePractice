#include <string>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.size();
        set<int>not_vis[2];
        for(int m=0;m<2;m++){
            for(int i=m;i<=n;i+=2){
                not_vis[m].insert(i);
            }
            not_vis[m].insert(n+1);
        }
        int start=0;
        for(char c:s){
            if(c=='0')start+=1;
        }
        vector<int>q={start};
        not_vis[start%2].erase(start);
        for(int ans=0;!q.empty();ans++){
            vector<int>nxt;
            for(int z:q){
                if(z==0)return ans;
                int mn=z+k-2*min(k,z);
                int mx=z+k-2*max(0,k-n+z);
                auto&st=not_vis[mn%2];
                for(auto it=st.lower_bound(mn);*it<=mx;it=st.erase(it)){
                    nxt.push_back(*it);
                }
            }
            q=move(nxt);
        }
        return -1;
    }
};