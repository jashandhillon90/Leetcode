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
    ListNode* partition(ListNode* head, int x) {
        // 2 dummy node bnayege ek large k liye or ek small k liye unko connect kr denge
        ListNode smalldummy(0);
        ListNode largedummy(0);
        ListNode* small=&smalldummy;
        ListNode* large=&largedummy;
        while(head!=NULL){
            if(head->val<x){
                small->next=head;// node ki list se jodte h
                small=small->next;// pointer aage badta h
            }else{
                //>= h toh large me
                large->next=head;
                large=large->next;
            }
            head=head->next;
        }
        large->next=NULL;//last node
        small->next=largedummy.next;
        return smalldummy.next;
    }
};