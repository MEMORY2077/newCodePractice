#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int nextBeautifulNumber(int n) {
            while(1){
                n++;
                int cnt[10]={0};
                for(int x=n;x>0;x/=10){
                    cnt[x%10]++;

                }
                bool beautiful=true;
                for(int x=n;x>0;x/=10){
                    if(cnt[x%10]!=x%10){
                        beautiful=false;
                        break;
                    }
                }
                if(beautiful)return n;
            }
            return n;
        }
    };