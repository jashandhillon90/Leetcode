class MyLinkedList {
    struct Node{
        int val;
        Node* next;
        Node(int x){
            val=x;
            next=NULL;
        }
    };
    Node* dummy;
    int size;

public:
    MyLinkedList() {
        dummy=new Node(0);
        size=0;
    }
    
    int get(int index) {
       if(index<0||index>=size)return -1;
       Node* curr=dummy->next;
       for(int i=0;i<index;i++){
        curr=curr->next;
       }    
       return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index<0)
        index=0;
        if(index>size)return;
        Node* prev=dummy;
        for(int i=0;i<index;i++){
            prev=prev->next;
        }
        Node* node=new Node(val);
        node->next=prev->next;//pahle jo prev ka next tha ab vo is node ka next hoga
        prev->next=node;
        size++;

    }
    
    void deleteAtIndex(int index) {
     if(index<0||index>=size)return;
     Node* prev=dummy;
     for(int i=0;i<index;i++){
        prev=prev->next;
     }        
     Node* temp=prev->next;//wo node khud
     prev->next=temp->next;//node k next ko previos ka next bna denge
     delete temp;
     size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */