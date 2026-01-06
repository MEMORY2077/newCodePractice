#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    public:
        static bool us2sort(const vector<string>&v1,const vector<string>&v2){
            int t1=stoi(v1[1]);
            int t2=stoi(v2[1]);
            if(t1<t2)return true;
            if(t1==t2){
                if(v1[0][0]=='O')return true;
            }
            return false;
        }
        vector<string>sp(string all){
            vector<string>ans;
            string user;
            for(char now:all){
                if(now=='i'||now=='d')continue;
                if(now==' '){
                    ans.push_back(user);
                    user.clear();
                    continue;
                }
                user.push_back(now);
            }
            if(user.length()!=0)ans.push_back(user);
            return ans;
        }
        vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
            sort(events.begin(),events.end(),us2sort);
            vector<int>ans(numberOfUsers,0);
            vector<int>Time(numberOfUsers,0);
            for(auto event:events){
                if(event[0][0]=='M'){
                    int time_stamp=stoi(event[1]);
                    //cout<<time_stamp<<endl;
                    if(event[2][0]=='A'){
                        for(int i=0;i<numberOfUsers;i++){
                            ans[i]++;
                        }
                        continue;
                    }
                    if(event[2][0]=='H'){
                        for(int i=0;i<numberOfUsers;i++){
                            if(Time[i]<=time_stamp)ans[i]++;
                        }
                        continue;
                    }
                    vector<string>users=sp(event[2]);
                    for(string user:users){
                        int u=stoi(user);
                        ans[u]++;
                    }
                }
                if(event[0][0]=='O'){
                    int time_stamp=stoi(event[1]);
                    //cout<<time_stamp<<endl;
                    int id=stoi(event[2]);
                    Time[id]=time_stamp+60;
                    continue;
                }
            }
            return ans;
        }
    };