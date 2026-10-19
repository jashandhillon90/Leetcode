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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(left==right)return head;
      ListNode dummy(0);
      dummy.next=head;
      ListNode *prev=&dummy;
      //ab prev ko just left ki pichli value tak lekr jayege
      for(int i=1;i<left;i++){
        prev=prev->next;
      }
      //ab reverse krege sublist ko
      ListNode *curr=prev->next;//left ko point kr rha h
      for(int i=0;i<right-left;i++){//kyuki nodes-1 operation perform hoyenge
      ListNode* temp=curr->next;
      curr->next=temp->next;
      temp->next=prev->next;
      prev->next=temp;
      }  
      return dummy.next;//means head
    }
};