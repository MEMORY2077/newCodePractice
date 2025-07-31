#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        int count=0;
        int n=s.size();
        char now='\0';
        vector<int>deleted(n,0);
        for(int i=0;i<n;i++){
            if(s[i]!=now){
                now=s[i];
                count=1;
            }
            else{
                count++;
                if(count==3){
                    deleted[i]=1;
                    count--;
                }
            }
            //cout<<now<<' '<<s[i]<<' '<<count<<endl;
        }
        string ans;
        for(int i=0;i<n;i++){
            if(deleted[i]==0){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};