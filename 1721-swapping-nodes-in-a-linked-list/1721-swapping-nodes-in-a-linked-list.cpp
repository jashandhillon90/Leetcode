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
    ListNode* swapNodes(ListNode* head, int k) {
       // 2 pointer bnayenge pahle ko k chalayenge then usko list k end tk lekr jayege taki dusra pointer jo uske saath chl rha h utna piche reh ske jitna pahle wala chla tha
       ListNode* fast=head;
       ListNode* slow=head;
       for(int i=1;i<k;i++){
        fast=fast->next;
       } 
       ListNode* first=fast;
       while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
       }
       ListNode* second=slow;
       swap(first->val,second->val);
       return head;
    }
};