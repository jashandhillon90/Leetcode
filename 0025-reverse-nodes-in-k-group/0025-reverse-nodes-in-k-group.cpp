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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* temp=head;
      //check krege k nodes present bhi h kya
      for(int i=0;i<k;i++){
        if(temp==NULL)return head;//k nodes present nhi h toh head se same return kredenge
        temp=temp->next;
      }  
      //reverse krege k nodes ko
      ListNode* curr=head;
      ListNode* prev=NULL;
      for(int i=0;i<k;i++){
        ListNode* nextNode=curr->next;
        curr->next=prev;//pichle node ko next bna denge
        prev=curr;
        curr=nextNode;
      }
      //remaining nodes k liye dubara recall krege
      head->next=reverseKGroup(curr,k);
      return prev;//nya head toh prev hi h reversed group ka
    }
};