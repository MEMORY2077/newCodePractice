#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string a;
        int ans=0x3f3f3f3f;
        int n=s.size();
        int l=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')res++;
            while(res>k){
                if(s[l]=='1')res--;
                l++;
            }
            while (res == k && s[l] == '0') l++;
            if(res==k&&i-l+1<ans){
                a=s.substr(l,i-l+1);
                ans=i-l+1;
            }
            else if(res==k&&i-l+1==ans){
                string now=s.substr(l,i-l+1);
                if(now<a)a=now;
            }
        }
        if(ans==0x3f3f3f3f)return "";
        return a;
    }
};