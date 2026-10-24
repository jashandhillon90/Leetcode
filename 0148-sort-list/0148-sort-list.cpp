/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
     // nodes ko single single krkr compare krke merge krege
    if(head==NULL||head->next==NULL) return head;
    //mid find krege
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
     //right part kaha se start hoga
     ListNode* right=slow->next;
     //left waha hi khatam mkr denge
     slow->next=NULL;
     //ab split krege And sort krege
     ListNode* left=sortList(head);
     right=sortList(right);
     //merge krege compare krke
     return merge(left,right);
    }
    ListNode* merge(ListNode* a,ListNode* b){
        if(a==NULL)return b;
        if(b==NULL)return a;
        if(a->val<=b->val){
            a->next=merge(a->next,b);
            return a;
        }else{
            b->next=merge(a,b->next);
            return b;
        }
    }
};