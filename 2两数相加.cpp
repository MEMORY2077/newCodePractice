#include <iostream>
#include "list.h"
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*p=l1;
        ListNode*q=l2;
        ListNode*ans=nullptr;
        ListNode*tail=nullptr;
        int plus=0;
        while(p&&q){
            int te=p->val+q->val+plus;
            p=p->next;
            q=q->next;
            plus=0;
            if(te>=10){
                te%=10;
                plus=1;
            }
            ListNode*temp=new ListNode(te);
            if(!ans){
                ans=temp;
                tail=temp;
            }
            else{
                tail->next=temp;
                tail=tail->next;
            }
        }
        if(p){
            ListNode*tp=p;
            while(tp&&plus){
                int te=tp->val+plus;
                plus=0;
                if(te>=10){
                    te%=10;
                    plus=1;
                }
                tp->val=te;
                if(tp->next==nullptr&&plus==1){
                    tp->next=new ListNode(1);
                    tail->next=p;
                    return ans;
                }
                else tp=tp->next;
            }
            tail->next=p;
            return ans;
        }
        if(q){
            ListNode*tp=q;
             while(tp&&plus){
                int te=tp->val+plus;
                plus=0;
                if(te>=10){
                    te%=10;
                    plus=1;
                }
                tp->val=te;
                if(tp->next==nullptr&&plus==1){
                    tp->next=new ListNode(1);
                    tp=tp->next;
                    tail->next=q;
                    return ans;
                }
                else tp=tp->next;
            }
            tail->next=q;
            return ans;
        }
        if(plus==1){
            tail->next=new ListNode(1);
        }
        return ans;
    }
};