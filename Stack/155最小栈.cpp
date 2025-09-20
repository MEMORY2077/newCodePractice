#include <stack>
#include <limits.h>
using namespace std;
class MinStack {
public:
    MinStack() {
        st.push({INT_MAX,INT_MAX});
    }
    
    void push(int val) {
        //0是当前，1是最小
        st.push({val,min(val,st.top().second)});        
    }
    
    void pop() {
        //跟我保证过了，我相信他
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
    stack<pair<int,int>>st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */