#include <vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int cardPoint:cardPoints){
            sum+=cardPoint;
        }
        int n=cardPoints.size();
        if(n==k)return sum;
        k=n-k;
        int dh=0;
        int m=0x3f3f3f3f;
        for(int i=0;i<n;i++){
            dh+=cardPoints[i];
            int l=i-k+1;
            if(l<0)continue;
            m=min(m,dh);
            dh-=cardPoints[l];
        }
        return sum-m;
    }
};