#include <vector>
#include <string>
using namespace std;
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int r=n-1;
        int l=0;
        int mid=0;
        int ans=0;
        while(l<=r){
            mid=(r-l)/2+l;
            if(letters[mid]<=target){
                l=mid+1;
            }
            else{
                r=mid-1;
                ans=mid;
            }
        }
        return letters[ans];
    }
};