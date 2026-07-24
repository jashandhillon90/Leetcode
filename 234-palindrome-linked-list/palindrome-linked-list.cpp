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
        ListNode* reverseList(ListNode* head) {
        ListNode* p=NULL;
        ListNode* curr=head;
        ListNode* n=NULL;
        while(curr!=NULL){
            n=curr->next;
            curr->next=p;
            p=curr;
            curr=n;
        }
        return p;
    }

       
     
          
      
         
      
        

    
 bool isPalindrome(ListNode* head) {
    if (!head || !head->next)
            return true;

     ListNode* fast=head;
     ListNode* slow=head;

       
       //Find middle
     while(fast->next&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
     }   
        // Reverse second half
        ListNode* second = reverseList(slow->next);

        // Compare both halves
        ListNode* first = head;
        ListNode* temp = second;

        while (temp) {
            if (first->val != temp->val)
                return false;
            first = first->next;
            temp = temp->next;
        }

        return true;
    
    }
};