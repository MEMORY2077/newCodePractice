#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int ans=0;
        int n=arrivals.size();
        set<int>toil;
        unordered_map<int,int>cnt;
        for(int i=0;i<n;i++){
            if(cnt[arrivals[i]]<m){
                cnt[arrivals[i]]++;
            }
            else{
                ans++;
                toil.emplace(i);
            }
            int l=i-w+1;
            if(l<0)continue;
            if(!toil.count(l))cnt[arrivals[l]]--;
        }
        return ans;
    }
};