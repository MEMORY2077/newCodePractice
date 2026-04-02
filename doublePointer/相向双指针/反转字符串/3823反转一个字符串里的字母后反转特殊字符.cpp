#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseByType(string s) {
        string sa;
        string sb;
        for(char c:s){
            if(c>='a'&&c<='z')sa.push_back(c);
            else sb.push_back(c);
        }
        //cout<<sa<<endl;
        //cout<<sb<<endl;
        reverse(sa.begin(),sa.end());
        reverse(sb.begin(),sb.end());
        int i=0,j=0;
        for(char &c:s){
            if(c>='a'&&c<='z'){
                c=sa[i];
                i++;
            }
            else{
                c=sb[j];
                j++;
            }
        }
        return s;
    }
};