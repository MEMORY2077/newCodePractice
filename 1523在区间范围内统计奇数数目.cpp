class Solution {
    public:
        int countOdds(int low, int high) {
            if((high-low+1)%2==0)return (high-low+1)/2;
            int count=0;
            if(high%2==1&&low%2==1)return (high-low+2)/2;
            return (high-low)/2;
            //5-7
        }
    };