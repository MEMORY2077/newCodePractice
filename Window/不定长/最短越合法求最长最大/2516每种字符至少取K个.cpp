#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>cnt('x',0);
        int n=s.size();
        for(char c:s){
            cnt[c]++;
        }
        if(cnt['a']<k||cnt['b']<k||cnt['c']<k)return -1;
        int l=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int x=s[i];
            cnt[x]--;
            while(cnt[x]<k){//注意这里，只要有一种不合法就应该缩小窗口
                cnt[s[l]]++;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return n-ans;
    }
};