#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        if(x<y){
            swap(x,y);
            for(int i=0;i<n;i++){
                if(s[i]=='a')s[i]='b';
                else if(s[i]=='b')s[i]='a';
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int cntA=0;
            int cntB=0;
            while(i<n&&(s[i]=='a'||s[i]=='b')){
                if(s[i]=='a'){
                    cntA++;
                }
                else{
                    if(cntA>0){
                        cntA--;
                        ans+=x;
                    }
                    else{
                        cntB++;
                    }
                }
                i++;
            }
            ans+=min(cntA,cntB)*y;
        }
        return ans;
    }
};