#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int>ans;
            unordered_map<char,int>edge;
            int n=s.size();
            for(int i=0;i<n;i++){
                edge[s[i]]=i;
            }
            int length=0;
            //要不要改成滑动窗口？
            //那就要两个循环了
            //left表示左边界，right表示右边界，然后用length刷新右边界
            //然后i在中间遍历，如果i超过right了就直接放入，然后修改左边界？
            int left=0,right=0;
            for(left;left<n;){
                //right=edge[s[left]];
                right=left;
                for(int i=left;i<=right;i++){
                    right=max(right,edge[s[i]]);//i遍历时顺便修改右边界
                }
                ans.push_back(right-left+1);
                left=right+1;
            }
            return ans;
        }
    };
            //记录每个字母最后出现的位置
            //判断当前字母的最后一个位置是否大于length
            //若大于，则要继续扩展到length
            //如果不大于呢，就不扩展
            //如果当前i已经超出length了，就放入ans长度，然后进行下一次扩展
int main(void){
    string s;
    cin>>s;
    Solution a;
    a.partitionLabels(s);
    cout<<1<<endl;
    return 0;
}
