#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        int r=k>0?k+1:n;
        k=abs(k);
        int s=0;
        for(int i=r-k;i<r;i++){
            s+=code[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=s;
            s+=code[r%n]-code[(r-k)%n];
            r++;
        }
        return ans;
    }
};