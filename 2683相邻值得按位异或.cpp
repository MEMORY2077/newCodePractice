#include <vector>
#include <iostream>
using namespace std;
//我蒙的？？？？？？
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=derived[0];
        for(int i=1;i<derived.size();i++){
            ans^=derived[i];
        }
        if(ans==1)return false;
        else return true;
    }
};