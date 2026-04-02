#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            cnt++;
            if(cnt==2*k){
                reverse(s.begin()+(i-2*k+1),s.begin()+i-k+1);
                cnt=0;
            }
        }
        if(cnt<k){
            reverse(s.begin()+(n-cnt),s.end());
        }
        else if(cnt>=k){
            reverse(s.begin()+n-cnt,s.begin()+n-cnt+k);
        }
        return s;
    }
};