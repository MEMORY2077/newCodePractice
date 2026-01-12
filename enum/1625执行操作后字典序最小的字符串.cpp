#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string findLexSmallestString(string s, int a, int b) {
            int n=s.size();
            int g=gcd(a,10);
            int step=gcd(b,n);
            string ans;
            for(int i=0;i<n;i+=step){
                string t=s.substr(i)+s.substr(0,i);
                modify(1,t,g);
                if(step%2==1){
                    modify(0,t,g);
                }
                if(ans.empty()||t<ans){
                    ans=t;
                }
            }
            return ans;
        }
        void modify(int start,string &t,int g){
            int ch=t[start]-'0';
            int add=ch%g-ch+10;
            for(int i=start;i<t.size();i+=2){
                t[i]='0'+(t[i]-'0'+add)%10;
            }
        }
    };