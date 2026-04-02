#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0;
        int now=0;
        int n=answerKey.length();
        unordered_map<char,int>cnt;
        int l=0;
        for(int i=0;i<n;i++){
            cnt[answerKey[i]]++;
            while(cnt['F']>k){
                cnt[answerKey[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        cnt.clear();
        l=0;
        for(int i=0;i<n;i++){
            cnt[answerKey[i]]++;
            while(cnt['T']>k){
                cnt[answerKey[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};