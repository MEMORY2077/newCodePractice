#include <iostream>
#include <queue>
#include "list.h"
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            ListNode*p=lists[i];
            while(p!=nullptr){
                pq.push({p->val,i});
                p=p->next;
            }
        }
        ListNode*ans=new ListNode(-1);
        ListNode*tail=ans;
        while(!pq.empty()){
            pair<int,int>now=pq.top();
            pq.pop();
            ListNode*next=lists[now.second];
            if(next!=nullptr){
            lists[now.second]=lists[now.second]->next;
            //pq.push({next->val,now.second});
            tail->next=next;
            tail=tail->next;
            tail->next=nullptr;
            }
        }
        return ans->next;
    }
};