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
    ListNode* mergeNodes(ListNode* head) {
     ListNode* curr=head->next;
     ListNode* ans=head;
     int sum=0;
     while(curr!=NULL){
     if(curr->val!=0){
        sum+=curr->val;
     }else{
        //agar 0 hogya then;
        ans->val=sum;
        ans->next=curr->next;
        ans=ans->next;
        sum=0;
     }
     curr=curr->next;
     }   
     return head;
    }
};