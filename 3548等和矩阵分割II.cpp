#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>>rotate(vector<vector<int>>&a){
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>>b(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                b[j][m-i-1]=a[i][j];
            }
        }
        return b;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        for(auto&row:grid){
            for(auto x:row){
                total+=x;
            }
        }
        return check(grid)||check(rotate(grid));
    }
    bool f(vector<vector<int>>&a){
        int m=a.size();
        int n=a[0].size();
        unordered_set<long long>st={0};
        long long s=0;
        for(int i=0;i<m-1;i++){
            auto&row=a[i];
            for(int j=0;j<n;j++){
                int x=row[j];
                s+=x;
                if(i>0||j==0||j==n-1){//第一行，不能删除中间元素
                    st.insert(x);
                }
            }
            if(n==1){
                if(s*2==total||s*2-total==a[0][0]||s*2-total==row[0]){//只有一列时候可以删最上面或最下面或者分界线
                    return true;
                }
                continue;
            }
            if(st.count(s*2-total))return true;
            if(i==0){
                for(int x:row){
                    st.insert(x);
                }
            }
        }
        return false;
    }
    bool check(vector<vector<int>>a){
        if(f(a))return true;
        reverse(a.begin(),a.end());
        return f(a);
    }
    long long total=0;
};