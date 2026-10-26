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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //pahle set me daal lenge saari value;
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* curr=dummy;
        while (curr->next!=NULL) {
            if (st.count(curr->next->val)){//check krenge ki value present h ki nhi
                curr->next=curr->next->next;
            }else{
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};