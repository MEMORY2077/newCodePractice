#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>tem;
        for(auto word:words){
            tem[word]++;
        }
        int k=words[0].size();
        vector<int>ans;
        int n=s.size();
        int length=k*words.size();
        unordered_map<string,int>real;
        for(int p=0;p<k;p++){
            real.clear();
            for(int i=p+k-1;i<n;i+=k){
                string t=s.substr(i-k+1,k);
                real[t]++;
                int l=i-length+1;
                if(l<0)continue;
                if(real==tem)ans.push_back(l);
                string o=s.substr(l,k);
                if(real.count(o)){
                    real[o]--;
                    if(real[o]==0)real.erase(o);
                }
            }
        }
        return ans;
    }
};