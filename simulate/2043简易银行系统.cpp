#include <bits/stdc++.h>
using namespace std;
class Bank {
    public:
        Bank(vector<long long>& balance):mib(balance),n(balance.size()){
            mib.insert(mib.begin(),0);
        }
        
        bool transfer(int account1, int account2, long long money) {
            if(account1<=0||account1>n||account2<=0||account2>n)return false;
            if(money>mib[account1])return false;
            mib[account1]-=money;
            mib[account2]+=money;
            return true;
        }
        
        bool deposit(int account, long long money) {
            if(account<=0||account>n)return false;
            mib[account]+=money;
            return true;
        }
        
        bool withdraw(int account, long long money) {
            if(account<=0||account>n||mib[account]<money)return false;
            mib[account]-=money;
            return true;
        }
    private:
        vector<long long>&mib;
        int n;
    };
    
    /**
     * Your Bank object will be instantiated and called as such:
     * Bank* obj = new Bank(balance);
     * bool param_1 = obj->transfer(account1,account2,money);
     * bool param_2 = obj->deposit(account,money);
     * bool param_3 = obj->withdraw(account,money);
     */