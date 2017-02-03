class MinStack {
private:
vector<int> stack;
int minIndex;
public:
    /** initialize your data structure here. */
    MinStack() {
        minIndex = -1;
    }
    
    void push(int x) {
        
        if(minIndex == -1){
            stack.push_back(x);
            minIndex = stack.size()-1;
        }
        else{
            stack.push_back(x);
            if(stack[minIndex] > x){
                minIndex = stack.size()-1;
            }
        }
        
        
    }
    
    void pop() {
        if(!stack.empty()){
            if(minIndex == stack.size()-1 && stack.size()>1){
                int minElem = stack[0];
                minIndex = 0;
                for(int i =stack.size()-2; i>0; i--){
                    if(minElem > stack[i]){
                        minElem = stack[i];
                        minIndex = i;
                    }
                }
            }
            stack.pop_back();
            if(stack.empty()){
                minIndex =-1;
            }
        }
    }
    
    int top() {
        if(!stack.empty())
            return stack.back();
    }
    
    int getMin() {
      //  cout << minIndex <<endl;
        if(!stack.empty() && minIndex!=-1)
            return stack[minIndex];
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