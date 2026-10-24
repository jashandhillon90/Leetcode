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
    ListNode* MergeTwoLists(ListNode* a,ListNode* b){
        if(a==NULL)return b;
        if(b==NULL)return a;
        if(a->val<=b->val){
            a->next=MergeTwoLists(a->next,b);
            return a;
        }else{
            b->next=MergeTwoLists(a,b->next);
            return b;//choti value h a ki value se next iske aage merge krege.
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     if(lists.empty())return NULL;
     ListNode* ans=lists[0];
     for(int i=1;i<lists.size();i++){
        ans=MergeTwoLists(ans,lists[i]);
     }   
     return ans;
    }
};