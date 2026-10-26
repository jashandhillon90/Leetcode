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
   vector<int> arr;//array bnayenge then zsaare node usi array me store krvayenge through constructor
    Solution(ListNode* head) {//constructor yeh h
    while(head!=NULL){
        arr.push_back(head->val);
        head=head->next;
    }
        
    }
    
    int getRandom() {
        int i=rand()%arr.size();//yeh randomly koi bhi index select krega
        return arr[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */