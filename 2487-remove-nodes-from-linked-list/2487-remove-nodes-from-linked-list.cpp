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
//right se traverse krna mushkil hota h toh pahle reverse krke maximum maintain krte rhenge or choti ko skip krdenge
   ListNode* reverse(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr!=NULL){
        ListNode* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;
   }
   
    ListNode* removeNodes(ListNode* head) {
     //pahle reverse krege
     head=reverse(head);
     int max=head->val;
     ListNode* curr=head;
     while(curr!=NULL&&curr->next!=NULL){
        if(curr->next->val<max){
            //toh skip krdenge
            curr->next=curr->next->next;
        }else{
            max=curr->next->val;
            curr=curr->next;
        }
     }   
     return reverse(head);
    }
};