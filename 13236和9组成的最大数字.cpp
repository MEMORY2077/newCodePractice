#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maximum69Number (int num) {
        int ans=0;
        stack<int>st;
        while(num!=0){
            st.push(num%10);
            num/=10;
        }
        while(!st.empty()){
            int now=st.top();
            st.pop();
            if(now==6){
                now=9;
                ans*=10;
                ans+=now;
                while(!st.empty()){
                    ans*=10;
                    now=st.top();
                    ans+=now;
                    st.pop();
                }
                return ans;
            }
            else{
                ans*=10;
                ans+=now;
            }
        }
        return ans;
    }
};