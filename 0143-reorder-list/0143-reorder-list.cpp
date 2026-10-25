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
    void reorderList(ListNode* head) {
       // list ko 2 half me baantkr dusri list ko reverse krke alternatively merge krege
       if(head==NULL||head->next==NULL)return;
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast->next!=NULL&& fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
       }
     ListNode* second=slow->next;
     slow->next=NULL;
     //ab 2nd list ko reverse kr denge
     ListNode* prev=NULL;
     ListNode* curr=second;
     while(curr!=NULL){
        ListNode* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
     }
     //reverse list 
     second=prev;
     //Ab Merge krege Alternatively
     ListNode* first=head;
     while(second!=NULL){
        ListNode* firstnext=first->next;
        ListNode* secondnext=second->next;
        first->next=second;
        second->next=firstnext;
        first=firstnext;
        second=secondnext;
     }
    }
};