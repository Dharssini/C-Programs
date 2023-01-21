class MyQueue {
    stack<int> input, output;
public:

    void push(int x) {
        input.push(x);
    }

    int pop(void) {
        int temp = peek(); //brilliant way
        
        output.pop();   
        return temp;
    }

    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop(); //to note
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

