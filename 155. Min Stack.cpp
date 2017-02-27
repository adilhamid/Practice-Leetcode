class MinStack {
    
public:
class Node{
    public:
    int val;
    int minVal;
    Node* next;

    Node(int x, int y ) : val(x), minVal(y), next(NULL){}
    Node(int x, int y, Node* ptr): val(x), minVal(y), next(ptr){} 
};

public:
Node* head;

public:
    void push(int x) {
        if(head ==NULL){
            head = new Node(x, x);
        }
        else{
            head = new Node(x, min(head->minVal, x), head);
        }
    }
    
    void pop() {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minVal;
    }
 
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */