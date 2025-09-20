#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int ans=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
                ans=max(ans,heights[i]);
            }
            else{
               while(!st.empty()&&heights[i]<=heights[st.top()]){
                    st.pop();
                }
                int now=0;
                if(st.empty()){
                    now=heights[i]*(i+1);
                }
                else now=max(heights[i]*(i-st.top()),heights[st.top()]*(i-st.top()+1));
                ans=max(ans,now);
                st.push(i);
            }
        }
        return ans;
    }
};