#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int>ans(k,0);
        int n=arr.size();
        int i=0,j=n-1;
        int m=arr[n/2];
        int l=0;
        for(i=0,j=n-1;i<j&&l<k;){
            if(abs(arr[i]-m)>abs(arr[j]-m)||abs(arr[i]-m)==abs(arr[j]-m)&&arr[i]>arr[j]){
                ans[l]=arr[i];
                i++;
                l++;
            }
            else {
                ans[l]=arr[j];
                j--;
                l++;
            }
        }
        return ans;
    }
};