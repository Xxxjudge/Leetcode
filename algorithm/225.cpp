class MyStack {
public:
    queue<int> myQue1;
    queue<int> myQue2;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myQue2.push(x);
        while(!myQue1.empty()) {
            myQue2.push(myQue1.front());
            myQue1.pop();
        }
        swap(myQue1,myQue2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp=myQue1.front();
        myQue1.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return myQue1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myQue1.empty();
    }
};