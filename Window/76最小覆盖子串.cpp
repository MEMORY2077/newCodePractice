#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool cover(int countS[],int countT[]){
        for(int i='a';i<='z';i++){
            if(countS[i]<countT[i]){
                return false;
            }
        }
        for(int i='A';i<='Z';i++){
            if(countS[i]<countT[i])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int countS[128]={0};
        int countT[128]={0};
        for(auto i:t){
            countT[i]++;
        }
        int m=s.size();
        int n=t.size();
        int left=0;
        int ans_left=-1;
        int ans_right=m;
        for(int right=0;right<m;right++){
            countS[s[right]]++;
            while(cover(countS,countT)){
                if(right-left<ans_right-ans_left){
                    ans_left=left;
                    ans_right=right;
                }
                countS[s[left]]--;
                left++;
            }
        }
        return ans_left<0?"":s.substr(ans_left,ans_right-ans_left+1);
    }
};