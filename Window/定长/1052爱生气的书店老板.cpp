#include <vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int sum=0;
        int allang=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            sum+=customers[i];
            allang+=customers[i]*grumpy[i];
        }
        int ang=0;
        for(int i=0;i<n;i++){
            ang+=grumpy[i]*customers[i];
            int l=i-minutes+1;
            ans=max(ang,ans);
            if(l<0)continue;
            ang-=grumpy[l]*customers[l];
        }
        allang-=ans;
        return sum-allang;
    }
};