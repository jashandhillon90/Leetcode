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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {//O(m+n)tc and sc both
     //2 lists ka sum nikalna h jese 7243+564=7807
     stack<int> s1,s2;
     while(l1!=NULL){
        s1.push(l1->val);
        l1=l1->next;
     }   
     while(l2!=NULL){
        s2.push(l2->val);
        l2=l2->next;
     }
     int carry=0;
     ListNode* head=NULL;
     //while loop chalayenge jab tk s1 s2 ya carry me value pdi h
     while(!s1.empty()||!s2.empty()||carry){
        int sum=carry;
        if(!s1.empty()){
            sum+=s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            sum+=s2.top();
            s2.pop();
        }
        carry=sum/10;
        // ab list bnayenge sum se pahle 7 add hoga then node ka next head yani  0 bnadenge or head me usi node ko store krenge jis se agli value uske aage jud ske
        ListNode* node=new ListNode(sum%10);
        node->next=head;
        head=node;
     }
     return head;
    }
};