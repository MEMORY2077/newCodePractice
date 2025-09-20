#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }
            else{
                int x=st.top();
                if(temperatures[x]>=temperatures[i]){
                    st.push(i);
                }
                else{
                    int count=0;
                    while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                        count++;
                        int x=st.top();
                        if(ans[x]==0)ans[x]=i-x;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return ans;
    }
};