#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool hasSameDigits(string s) {
            while(s.size()>2){
                for(int i=0;i<s.size()-1;i++){
                    int a=((s[i]-'0')*10+s[i+1]-'0')%10;
                    s[i]=a+'0';
                }
                s.pop_back();
            }
            if(s[0]==s[1])return true;
            return false;
        }
    };