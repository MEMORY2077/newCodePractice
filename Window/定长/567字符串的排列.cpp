#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>cnt_s1;
        unordered_map<char,int>cnt_s2;
        for(auto s:s1){
            cnt_s1[s]++;
        }
        int n=s2.size();
        int k=s1.size();
        for(int i=0;i<n;i++){
            cnt_s2[s2[i]]++;
            int l=i-k+1;
            if(l<0)continue;
            if(cnt_s1==cnt_s2)return true;
            cnt_s2[s2[l]]--;
            if(cnt_s2[s2[l]]==0)cnt_s2.erase(s2[l]);
        }
        return false;
    }
};