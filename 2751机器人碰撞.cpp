#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>idx(n,0);
        for(int i=0;i<n;i++){
            idx[i]=i;
        } 
        sort(idx.begin(),idx.end(),[&](int a,int b){return positions[a]<positions[b];});
        stack<int>st;
        for(int i:idx){
            if(directions[i]=='R'){
                st.push(i);
                continue;
            }
            while(!st.empty()){
                int j=st.top();
                if(healths[i]<healths[j]){
                    healths[j]-=1;
                    healths[i]=0;
                    break;
                }
                if(healths[i]==healths[j]){
                    healths[j]=0;
                    healths[i]=0;
                    st.pop();
                    break;
                }
                healths[i]-=1;
                healths[j]=0;
                st.pop();
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(healths[i]>0)ans.push_back(healths[i]);
        }
        return ans;
    }
};