#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* modifiedList(vector<int>& nums, ListNode* head) {
            unordered_set<int>h(nums.begin(),nums.end());
            ListNode *fakehead=new ListNode(-1,head);
            head=fakehead;
            ListNode*p=head;
            while(p->next!=nullptr){
                if(h.find(p->next->val)!=h.end()){
                    p->next=p->next->next;
                }
                else p=p->next;
            }
            return fakehead->next;
        }
    };