
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> mp;
        int sum = 0;
        // First traversal store the last node for each prefix sum
        for(ListNode* curr=dummy;curr!=NULL;curr=curr->next){
            sum+=curr->val;
            mp[sum]=curr;
        }
        sum = 0;
        // Second traversal skip zero-sum sublists
        for(ListNode* curr=dummy;curr!=NULL;curr=curr->next) {
            sum+=curr->val;
            curr->next=mp[sum]->next;
        }
        return dummy->next;
    }
};
