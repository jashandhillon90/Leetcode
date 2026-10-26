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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int count = 0;
        while(head!=NULL){
            //pahli condition me check krenge ki head ki val present h ki nhi set me next condition check kregi kya yeh last node h or head k next ki value present nhi h set me toh hi vo group consider kiya jayega
            if (st.count(head->val)&&(head->next==NULL||!st.count(head->next->val))) {
                count++;
            }
            head=head->next;
        }
        return count;
    }
};