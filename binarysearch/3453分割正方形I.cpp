#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>squares;
    double total_area = 0;
    bool check(double y){
        double area = 0;
        for(vector<int>square:squares){
            if (square[1]<y){
                area += square[2]*(min(y-square[1],(double)square[2]));
            }
        }
        return area>=total_area/2;
    }
    double separateSquares(vector<vector<int>>& squares) {
        this -> squares = squares;
        double right=0;
        for (vector<int>now:squares){
            total_area += (now[2]*now[2]);
            right = max(right,(double)(now[1]+now[2]));
        }
        double left = 0;
        double max_y = right;
        int count = log2(max_y*100000);
        double mid = 0;
        for (int i=0;i<count;i++){
            mid = (left+right)/2;
            if (check(mid)){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return (left+right)/2;
    }
};