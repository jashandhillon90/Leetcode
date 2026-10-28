class MyCircularQueue {
public:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int count;
    MyCircularQueue(int k) {
       arr.resize(k);
       front=0;
       rear=-1;
       size=k;
       count=0; 
    }
    //tc o(1)sc o(k)
    bool enQueue(int value) {
        if(isFull())
            return false;
        rear=(rear+1)%size;//kyuki maximum k element store ho skte h then dubara starting se
        arr[rear]=value;
        count++;
        return true;
    }
    
    bool deQueue(){
        if(isEmpty())
            return false;
        front=(front+1)%size;
        count--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return arr[front];
    }
    
    int Rear() {
     if(isEmpty())
            return -1;
        return arr[rear];   
    }
    
    bool isEmpty() {
       return count==0; 
    }
    
    bool isFull() {
        return count==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */