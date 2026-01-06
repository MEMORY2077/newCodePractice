#include <vector>
#include <string>
using namespace std;
//只需要看每一列是否为严格递增即可。。。吧
//从左向右遍历每一列，如果严格递增，则直接返回
//如果是递减，就应该删除这一列，count++,看下一列
class Solution {
    public:
        int minDeletionSize(vector<string>& strs) {
            int n=strs[0].size();
            int m=strs.size();
            int ans=0;
            vector<string>t(m);
            for(int i=0;i<n;i++){//遍历每一列
                bool flag=true;
                for(int j=1;j<m;j++){
                    //cout<<i<<' '<<j<<endl;
                    if(t[j]+strs[j][i]<t[j-1]+strs[j-1][i]){//没有递增
                        ans++;
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    for(int j=0;j<m;j++){
                        t[j]+=strs[j][i];
                    }
                }
            }
            return ans;
        }
    };