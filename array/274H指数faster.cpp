#include <algorithm>
#include <vector>
using namespace std;
bool us2sort(int &a,int &b){
    return a>=b;
}
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int>count(n+1,0);
        for(int citation:citations){
            count[min(citation,n)]+=1;
        }
        for(int i=n-1;i>=0;i--){
            count[i]+=count[i+1];
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            if(i>count[i])return ans;
            ans=i;
        }
        return ans;
    }
};