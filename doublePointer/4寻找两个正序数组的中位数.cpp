#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        int m=nums1.size();
        int n=nums2.size();
        nums1.insert(nums1.begin(),INT_MIN);
        nums2.insert(nums2.begin(),INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int j=(m+n+1)/2;
        int i=0;
        while(1){
            if(nums1[i]<=nums2[j+1]&&nums1[i+1]>nums2[j]){
                int max1=max(nums1[i],nums2[j]);
                int min2=min(nums1[i+1],nums2[j+1]);
                if((m+n)%2==1)return max1;
                else return (max1+min2)/2.0;

            }
            i++;
            j--;
        }
        return 0;
    }
};