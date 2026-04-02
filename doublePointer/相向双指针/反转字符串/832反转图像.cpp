#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &row:image){
            for(int i=0,j=row.size()-1;i<j;i++,j--){
                swap(row[i],row[j]);
            }
            for(auto &num:row){
                num=1-num;
            }
        }
        return image;
    }
};