class Solution {
public:
    bool checkPowersOfThree(int n) {
        int now=1;
        while(n!=0){
            if(n%3==2)return false;
            n/=3;
        }
        return true;
    }
};