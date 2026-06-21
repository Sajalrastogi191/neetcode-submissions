class MyQueue {
private:
    stack<int> in_stack;
    stack<int> out_stack;

    // Helper function to move elements from in_stack to out_stack when needed
    void shiftStacks() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }

public:
    MyQueue() {
        // Constructor
    }
    
    // Push element x to the back of the queue.
    void push(int x) {
        in_stack.push(x);
    }
    
    // Removes the element from the front of the queue and returns it.
    int pop() {
        shiftStacks();
        int frontElement = out_stack.top();
        out_stack.pop();
        return frontElement;
    }
    
    // Returns the element at the front of the queue.
    int peek() {
        shiftStacks();
        return out_stack.top();
    }
    
    // Returns true if the queue is empty, false otherwise.
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};