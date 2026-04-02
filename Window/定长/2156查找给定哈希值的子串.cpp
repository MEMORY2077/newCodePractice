#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string subStrHash(string s, int power, int m, int k, int hashValue) {
        unordered_map<char,int>val;
        for(int i=0;i<26;i++){
            val['a'+i]=i+1;
        }
        long long int res=0;
        long long int mp=1;
        for(int i=0;i<k-1;i++){
            mp=(mp*power)%m;
        }
        int ans=0;
        int n=s.size();
        for(int l=n-1;l>=0;l--){
            res=(res*power)%m;
            res=(res+val[s[l]])%m;
            int r=l+k-1;
            if(r>=n)continue;
            if(res==hashValue)ans=l;
            res=(res-val[s[r]]*mp%m+m)%m;
            //res=(res/power)%m;
        }
        return s.substr(ans,k);
    }
};