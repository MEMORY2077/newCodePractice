#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int k=0;
        stack<int>temp;
        int n=pushed.size();
        for(int i=0;i<n;i++){
            while(!temp.empty()&&temp.top()!=popped[i]){
                if(k>=n)return false;
                temp.push(pushed[k++]);
            }
            temp.pop();
        }
        return true;
    }
};