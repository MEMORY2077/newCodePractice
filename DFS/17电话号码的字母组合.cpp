#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string now;
        if(digits.size()==0)return {};
        dfs(digits,now,0);
        return ans;
    }
    void dfs(string &digits,string now,int next){
        if(next==digits.size()){
            ans.push_back(now);
            return;
        }
        int num=digits[next]-'0';
        int size=keyboard[num].size();
        for(int i=0;i<size;i++){
            now.push_back(keyboard[num][i]);
            dfs(digits,now,next+1);
            now.pop_back();
        }
        return;
    }
    vector<string>ans;
    vector<string>keyboard={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
};