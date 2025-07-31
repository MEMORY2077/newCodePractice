#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    static const int MOD=1000000007;
public:
    int possibleStringCount(string word, int k) {
        int ans=1;
        vector<int>cnts;
        int cnt=0;
        for(int i=0;i<word.size();i++){
            cnt++;
            if(i==word.size()-1||word[i]!=word[i+1]){
                if(cnt>1){
                    if(k>0){
                        cnts.push_back(cnt-1);//每组都至少要拿一个，拿的这个不参与运算
                    }
                    ans=ans*cnt%MOD;
                }
                k--;
                cnt=0;
            }
        }
        if(k<=0){
            //组数比原串长度还要长，没有比k小的原串，直接返回ans
            return ans;
        }
        int m=cnts.size();//组数
        vector<vector<int>>f(m+1,vector<int>(k));//现在的k是减去组数(每组至少一个)的k，即还要选k个字母出来
        for(int i=0;i<k;i++){
            f[0][i]=1;//什么都不选，一种选法
        }
        vector<int>s(k+1);//f[i]的前缀和
        for(int i=0;i<m;i++){
            for(int j=0;j<k;j++){
                s[j+1]=(s[j]+f[i][j])%MOD;
            }
            for(int j=0;j<k;j++){
                f[i+1][j]=(s[j+1]-s[max(j-cnts[i],0)])%MOD;
            }
        }
        return (ans-f[m][k-1]+MOD)%MOD;
    }
};