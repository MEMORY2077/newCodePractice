#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int ans=0;
        int l=0;
        int n=tiles.size();
        int can=0;
        for(int r=0;r<n;r++){
            can+=(tiles[r][1]-tiles[r][0]+1);
            int car_left=tiles[r][1]-carpetLen+1;
            while(tiles[l][1]<car_left){
                can-=(tiles[l][1]-tiles[l][0]+1);
                l++;
            }
            int uncan=max(car_left-tiles[l][0],0);
            ans=max(can-uncan,ans);
        }
        return ans;
    }
};