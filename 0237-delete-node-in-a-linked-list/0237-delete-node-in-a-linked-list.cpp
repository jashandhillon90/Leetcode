/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //hme pointer de rkha h jo node nelete krna h na ki head diya hua h
        //node ki value me node k next ki value store krdenge or next node ko skip kr denge
        node->val=node->next->val;
        node->next=node->next->next;
    }
};