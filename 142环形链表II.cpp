#include <iostream>
#include "list.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //if(!head||!head->next)return head;
        ListNode*p=head;
        ListNode*q=head;
        while(q&&q->next){
            p=p->next;
            q=q->next->next;
            if(p==q){
                ListNode*ans=head;
                while(ans!=p){
                ans=ans->next;
                p=p->next;
                }
                return ans;
            };
        }
        /*if(!p||!q)return nullptr;
        ListNode*ans=head;
        while(ans&&p){
            ans=ans->next;
            p=p->next;
            if(ans==p)break;
        }
        return ans;*/
        return nullptr;
    }
};