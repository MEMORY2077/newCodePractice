#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        for(int i=0;i<n;i++){
            if(s[i]>='A'&&s[i]<='Z')s[i]-=('A'-'a');
        }
        while(1){
            while(l<n&&!(isalpha(s[l])||s[l]>='0'&&s[l]<='9'))l++;
            while(r>=0&&!(isalpha(s[r])||s[r]>='0'&&s[r]<='9'))r--;
            if(l>=r)return true;
            if(s[l]!=s[r])return false;
            l++;
            r--;
            if(l>=r)return true;
        }
        return true;
    }
};