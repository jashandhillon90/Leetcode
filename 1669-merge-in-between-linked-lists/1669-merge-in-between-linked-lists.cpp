class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        // Reach node at index a-1
        for(int i=0;i<a-1;i++) {
            prev = prev->next;
        }
        // Reach node at index b+1
        ListNode* after = prev;
        for (int i=0;i<b-a+2;i++){
            after=after->next;
        }
        // Reach last node of list2
        ListNode* tail = list2;
        while(tail->next!=NULL) {
            tail=tail->next;
        }
        // Connect both lists
        prev->next=list2;
        tail->next=after;
        return list1;
    }
};