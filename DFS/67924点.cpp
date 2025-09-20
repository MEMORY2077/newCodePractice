#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    const double EPS=1e-9;
    bool judgePoint24(vector<int>& cards) {
        vector<double>a(cards.begin(),cards.end());
        return dfs(a);
    }
    bool dfs(vector<double>cards){
        if(cards.size()==1){
            if(abs(cards[0]-24)<=EPS)return true;
            return false;
        }
        int n=cards.size();
        for(int i=0;i<n;i++){
            double x=cards[i];
            for(int j=i+1;j<n;j++){
                double y=cards[j];
                vector<double>candidates={x+y,x-y,x*y,y-x};
                if(abs(x)>EPS)candidates.push_back(y/x);
                if(abs(y)>EPS)candidates.push_back(x/y);
                vector<double>newCards=cards;
                newCards.erase(newCards.begin()+j);
                for(double now:candidates){
                    newCards[i]=now;
                    if(dfs(newCards))return true;
                }
            }
        }
        return false;
    }
};