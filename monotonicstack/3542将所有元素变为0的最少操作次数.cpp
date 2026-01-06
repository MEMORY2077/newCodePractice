#include <stack>
#include <vector>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums) {
            stack<int>s;
            int ans=0;
            for(int num:nums){
                while(!s.empty()&&s.top()>num){
                    s.pop();
                    ans++;
                }
                if(num!=0&&(s.empty()||s.top()!=num))s.push(num);
            }
            while(!s.empty()){
                s.pop();
                ans++;
            }
            return ans;
        }
    };