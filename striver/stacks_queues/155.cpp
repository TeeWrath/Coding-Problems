#include <bits/stdc++.h>
using namespace std;

// My solution, very bad in time complexity
class StackNode
{
public:
    int val;
    StackNode *next;
    int minVal;

public:
    StackNode()
    {
        next = nullptr;
        minVal = INT_MAX;
    }
};

class MinStack
{
public:
    // StackNode st;
    StackNode *stackTop = new StackNode();
    MinStack()
    {
    }

    void push(int val)
    {
        StackNode *tmp = new StackNode();
        tmp->val = val;
        tmp->next = stackTop;
        tmp->minVal = min(tmp->val, stackTop->minVal);
        stackTop = tmp;
        cout << "Pushed element into the stack: " << val << endl;
    }

    void pop()
    {
        StackNode *tmp = stackTop;
        cout << "Popping element out: " << stackTop->val << endl;
        stackTop = stackTop->next;
        delete tmp;
    }

    int top()
    {
        return stackTop->val;
    }

    int getMin()
    {
        return stackTop->minVal;
    }

    void printStack(){
        StackNode* tmp = stackTop;
        cout << "Current status of stack: ";
        while(tmp != nullptr){
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

// Better solution - using pairs
class MinStackPair {
    public:
        stack<pair<int,int>> st;
        MinStackPair() {
            
        }
        
        void push(int val) {
            int x;
            if(st.empty()) x = val;
            else x = min(st.top().second,val);
            st.push({val,x});
        }
        
        void pop() {
            st.pop();
        }
        
        int top() {
            return st.top().first;
        }
        
        int getMin() {
            return st.top().second;
        }
    };

// Most optimum solution
class MinStackMaxOptimum {
    public:
        stack<long long> st;
        long long minimum = INT_MAX;
        
        MinStackMaxOptimum() {
        }
        
        void push(int val) {
            if (st.empty()) {
                st.push(val);
                minimum = val;
                return;
            }
            if (val < minimum) {
                st.push(2LL * val - minimum); // Use 2LL to avoid overflow
                minimum = val;
            } else {
                st.push(val);
            }
        }
        
        void pop() {
            if (st.empty()) return; // Safety check
            if (st.top() < minimum) {
                minimum = 2LL * minimum - st.top(); // Restore previous minimum
            }
            st.pop();
        }
        
        int top() {
            if (st.top() < minimum) {
                return minimum; // Return the actual value (not the encoded value)
            }
            return st.top();
        }
        
        int getMin() {
            return minimum;
        }
    };

int main()
{
    MinStack mn = MinStack();
    mn.printStack();
    mn.push(-2);
    mn.printStack();
    mn.push(0);
    mn.printStack();
    mn.push(-3);
    mn.printStack();
    cout << "Current Minimum: " << mn.getMin() << endl;
    mn.printStack();
    mn.pop();
    mn.printStack();
    cout << "Current top element: " << mn.top() << endl;
    mn.printStack();
    cout << "Current Minimum: " << mn.getMin() << endl;
    mn.printStack();
    return 0;
}