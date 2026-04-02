#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n=word.length();
        int ans=0;
        for(int i=0;i<n;){
            int st=i;
            for(i++;i<n&&abs(word[i]-word[i-1])<=2;i++);
            ans+=f(word.substr(st,i-st),k);
        }
        return ans;
    }
private:
    int f(string word,int k){
        int n=word.size();
        int res=0;
        for(int s=1;s<=26&&s*k<=n;s++){
            vector<int>cnt(26,0);
            for(int i=0;i<n;i++){
                cnt[word[i]-'a']++;
                int l=i-s*k+1;
                if(l<0)continue;
                for(int j=0;j<26;j++){
                    if(cnt[j]&&cnt[j]!=k){
                        res--;
                        break;
                    }
                }
                res++;
                cnt[word[l]-'a']--;
            }
        }
        return res;
    }
};