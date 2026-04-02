#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=n;
        for(int i=0;i<n;i++){
            int start;
            if(i>0&&ratings[i-1]<ratings[i])start=i-1;
            else start=i;
            while(i+1<n&&ratings[i]<ratings[i+1]){//上坡
                i++;
            }
            int top=i;
            while(i+1<n&&ratings[i]>ratings[i+1]){
                i++;
            }
            int inc=(top-start);//严格递增段
            int dec=(i-top);//严格递减段
            ans+=((inc*(inc-1))+(dec*(dec-1)))/2+max(inc,dec);
        }
        return ans;
    }
};