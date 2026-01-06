#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Spreadsheet {
public:
    Spreadsheet(int rows) {
        sheet=vector<vector<int>>(26,vector<int>(rows+1,0));
    }
    
    void setCell(string cell, int value) {
        pair<int,int>address=getaddress(cell);
        sheet[address.first][address.second]=value;
    }
    
    void resetCell(string cell) {
        pair<int,int>address=getaddress(cell);
        sheet[address.first][address.second]=0;        
    }
    
    int getValue(string formula) {
        int i=1;
        string a;
        while(formula[i]!='+'){
            a+=formula[i];
            i++;
        }
        i++;
        string b=formula.substr(i);
        int x=0;
        int y=0;
        if(a[0]>='A'&&a[0]<='Z'){
            auto aa=getaddress(a);
            x=sheet[aa.first][aa.second];
        }
        else {
            for(int i=0;i<a.size();i++){
                x*=10;
                x+=(a[i]-'0');
            }
        }
        if(b[0]>='A'&&b[0]<='Z'){
            auto ab=getaddress(b);
            y=sheet[ab.first][ab.second];
        }
        else {
            for(int i=0;i<b.size();i++){
                y*=10;
                y+=(b[i]-'0');
            }
        }        
        return x+y;
    }
    pair<int,int> getaddress(string cell){
        int x=cell[0]-'A';
        int y=0;
        for(int i=1;i<cell.size();i++){
            y*=10;
            y+=(cell[i]-'0');
        }
        return {x,y};
    }
    vector<vector<int>>sheet;
};
int main(void){
    Spreadsheet*obj=new Spreadsheet(3);
    obj->getValue("=5+7");

}
/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */