#include <vector>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0;
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int l=i-k+1;
            if(l<0)continue;
            if(1.0*sum/k>=threshold)ans++;
            sum-=arr[l];
        }
        return ans;
    }
};