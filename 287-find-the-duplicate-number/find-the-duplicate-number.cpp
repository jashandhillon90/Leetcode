class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow=arr[0],fast=arr[0]; //linkedlist assume kr lenge
        do{
           slow=arr[slow];//+1
            fast=arr[arr[fast]];//+2
        }while(slow!=fast);
        slow=arr[0]; //dubara first pointer to point krega or next element cycle create krega jab fast slow k equal hoga in linkedlist.
        while(slow!=fast){
            slow=arr[slow];//+1
            fast=arr[fast];//+1

        }return fast;
    }
 };