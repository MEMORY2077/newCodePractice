#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        int left=binarysearch(fruits,n-1,startPos-k);
        int right=left;
        int s=0;
        for(right;right<n&&fruits[right][0]<=startPos;right++){
            s+=fruits[right][1];
        }
        int ans=s;
        for(right;right<n&&fruits[right][0]<=startPos+k;right++){
            s+=fruits[right][1];
            while(fruits[right][0]*2-fruits[left][0]-startPos>k&&fruits[right][0]-fruits[left][0]*2+startPos>k){
                s-=fruits[left][1];
                left++;
            }
            ans=max(ans,s);
        }
        return ans;
    }
    int binarysearch(vector<vector<int>>address,int start,int target){
        int left=0;
        int ans=start+1;
        int right=start;
        int mid=(right-left)/2+left;
        while(left<=right){
            mid=(right-left)/2+left;
            if(address[mid][0]>=target){
                right=mid-1;
                ans=mid;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};