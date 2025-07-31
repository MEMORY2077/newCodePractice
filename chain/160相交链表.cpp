#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*p=headA;
        ListNode*q=headB;
        int countA=0;
        int countB=0;
        while(p!=nullptr){
            countA++;
            p=p->next;
        }
        while(q!=nullptr){
            countB++;
            q=q->next;
        }
        cout<<countA<<' '<<countB<<endl;
        if(countA<countB){
            ListNode *temp=headA;
            headA=headB;
            headB=temp;
            int t=countA;
            countA=countB;
            countB=t;
        }
        int sub=countA-countB;
        cout<<sub<<endl;
        p=headA;
        q=headB;
        while(sub>0){
            p=p->next;
            sub--;
        }
        while(countB>0){
            if(p==q&&p!=nullptr)return p;
            p=p->next;
            q=q->next;
            countB--;
        }
        return nullptr;
    }
};