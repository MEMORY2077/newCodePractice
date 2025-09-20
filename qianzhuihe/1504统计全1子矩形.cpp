#include <vector>
using namespace std;
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        for(int top=0;top<m;top++){
            vector<int>a(n);
            for(int bottom=top;bottom<m;bottom++){
                int h=bottom-top+1;
                int last=-1;
                for(int j=0;j<n;j++){
                    a[j]+=mat[bottom][j];
                    if(a[j]!=h){
                        last=j;
                    }
                    else{
                        ans+=(j-last);
                    }
                }
            }
        }
        return ans;
    }
};