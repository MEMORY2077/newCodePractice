#include <iostream>
#include "list.h"
using namespace std;
class Solution {
public:
    ListNode* middleNode(ListNode*head){
        ListNode*f=head;
        ListNode*s=head;
        ListNode*pre;
        cout<<1141<<' ';
        while(f&&f->next){
            cout<<1141<<' ';
            pre=s;
            f=f->next->next;
            s=s->next;
        }
        cout<<1141<<' ';
        pre->next=nullptr;
        cout<<1141<<' ';
        return s;
    }
    ListNode* mergeNode(ListNode*head,ListNode*head2){
        ListNode*ans=nullptr;
        ListNode*tail=nullptr;
        ListNode*p=head;
        ListNode*q=head2;
        while(p&&q){
            ListNode*temp;
            if(p->val<q->val){
                temp=p;
                p=p->next;
            }
            else{
                temp=q;
                q=q->next;
            }
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
            tail->next=p;
        }
        if(q){
            tail->next=q;
        }
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        printf("1");
        ListNode*head2=middleNode(head);
        printf("2");
        head=sortList(head);
        printf("3");
        head2=sortList(head2);
        printf("4");
        return mergeNode(head,head2);
    }
};