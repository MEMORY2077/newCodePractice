#include <vector>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>cur={1.0*poured};
        for(int i=1;i<=query_row;i++){
            vector<double>nextrow(i+1,0);
            for(int j=0;j<cur.size();j++){
                double x=cur[j]-1;
                if(x>0){
                    nextrow[j]+=x/2;
                    nextrow[j+1]+=x/2;
                }
            }
            cur=nextrow;
        }
        return min(cur[query_glass],1.0);
    }
};