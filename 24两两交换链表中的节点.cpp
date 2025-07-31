#include "list.h"
using namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode*fakehead=new ListNode(-1,head);
        ListNode*p=fakehead->next;
        ListNode*pre=fakehead;
        while(p&&p->next){
            ListNode*temp=p->next;
            p->next=p->next->next;
            pre->next=temp;
            temp->next=p;
            pre=p;
            p=p->next;
        }
        return fakehead->next;
    }
};