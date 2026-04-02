#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int l=0;
        int n=arr.size();
        int i,j;
        for(i=0,j=n-1;i<j&&j-i+1>k;){
            if(abs(arr[i]-x)<abs(arr[j]-x)||abs(arr[i]-x)==abs(arr[j]-x)&&arr[i]<arr[j])j--;
            else i++;
        }
        ans=vector<int>(arr.begin()+i,arr.begin()+j+1);
        return ans;
    }
};