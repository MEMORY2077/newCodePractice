#include <vector>
#include <string>
using namespace std;
//和2一样吧，就是多了个判断条件？
class Solution {
    public:
        int minDeletionSize(vector<string>& strs) {
            int n=strs[0].size();
            int m=strs.size();
            int ans=0;
            vector<string>row(n);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    row[i]+=strs[j][i];//存一下
                }
            }
            for(int i=0;i<n;i++){
                cout<<row[i]<<endl;
            }
            vector<string>col(m);
            for(int i=0;i<n;i++){
                bool flag=true;
                for(int j=1;j<m;j++){//昨天的列上判断
                    //串1
                    //串2
                    //串3
                    if(col[j]+strs[j][i]<col[j-1]+strs[j-1][i]){
                        ans++;
                        flag=false;
                        break;
                    }
                }
                if(flag){//列上没问题，行上呢
                    //串串串
                    //1 2 3
                    if(i>0&&row[i]<row[i-1]){
                        ans++;
                        flag=false;
                    }
                }
                if(flag){
                    for(int j=0;j<m;j++){
                        col[j]+=strs[j][i];
                    }
                }
            }
            return ans;
        }
    };