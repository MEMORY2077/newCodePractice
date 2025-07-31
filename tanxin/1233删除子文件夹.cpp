#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool startwith(string&source,string&target){
        int n=target.size();
        for(int i=0;i<n;i++){
            if(source[i]!=target[i])return false;
        }
        if(source[n]!='/')return false;
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n=folder.size();
        vector<string>ans;
        ans.push_back(folder[0]);
        //cout<<ans.back()<<endl;
        int next=1;
        while(next<n){
            if(startwith(folder[next],ans.back())){
                next++;
                continue;
            }
            else{
                ans.push_back(folder[next]);
                next++;
                continue;
            }
        }
    return ans;
    }
};