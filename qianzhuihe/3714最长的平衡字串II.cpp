#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int ans=0;
    string s;
    void twochar(char a,char b){
        int n=s.size();
        vector<int>nums(n,0);
        unordered_map<int,int>h;
        for(int i=0;i<n;i++){
            if(s[i]!=a&&s[i]!=b)continue;
            h.clear();
            h[0]=i-1;
            int diff=0;
            while(i<n&&(s[i]==a||s[i]==b)){
                diff+=(s[i]==a)?1:-1;
                if(h.find(diff)!=h.end())ans=max(ans,i-h[diff]);
                else h[diff]=i;
                i++;
            }
        }
    }
    int longestBalanced(string s) {
        this->s=s;
        //一种字符最长子串
        ans=1;
        int c=1;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                c++;
            }
            else{
                c=1;
            }
            ans=max(ans,c);
        }

        //两种字符最长子串
        twochar('a','b');
        twochar('a','c');
        twochar('b','c');
        //三种
        unordered_map<long long,int>h={{getId(0,0),-1}};
        int pre[3]={0,0,0};
        for(int i=0;i<n;i++){
            pre[s[i]-'a']++;
            long long id=getId(pre[1]-pre[0],pre[1]-pre[2]);
            if(h.find(id)!=h.end()){
                ans=max(ans,i-h[id]);
            }
            else h[id]=i;
        }
        return ans;
    }
    long long getId(int x,int y){
        int n=s.size();
        return 1LL*(x+n)<<32|(y+n);
    }
};