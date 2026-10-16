#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> prefMin;
    stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        if(!prefMin.empty() && val < prefMin.top())prefMin.push(val);
        else {
            if(!prefMin.empty())prefMin.push(prefMin.top());
            else prefMin.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        prefMin.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return prefMin.top();
    }
};

int main(){
    MinStack minStack = MinStack();
    minStack.push(5);
    cout << "Top ele: "<< minStack.top() << endl;
    cout << "MIN ele: "<< minStack.getMin() << endl;
    minStack.push(6);
    cout << "Top ele: "<< minStack.top() << endl;
    cout << "MIN ele: "<< minStack.getMin() << endl;
    minStack.push(2);
    cout << "Top ele: "<< minStack.top() << endl;
    cout << "MIN ele: "<< minStack.getMin() << endl;

    // popping sequence
    minStack.pop();
    cout << "Top ele: "<< minStack.top() << endl;
    cout << "MIN ele: "<< minStack.getMin() << endl;
    minStack.pop();
    cout << "Top ele: "<< minStack.top() << endl;
    cout << "MIN ele: "<< minStack.getMin() << endl;
}