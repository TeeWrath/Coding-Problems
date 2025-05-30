#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q;
    queue<int> cp;
    
    public:
    void push(int x){
        int s = q.size();
        q.push(x);

        for(int i=0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
        cp =q;
    }

    int pop(){
        int v = q.front();
        q.pop();
        cp = q;
        return v;
    }

    int returnTop(){
        return q.front();
    }

    int returnSize(){
        return q.size();
    }

    void printStack(){
        cout << "Current status of the stack: " << endl;
        for(int i=0; i< q.size(); i++){
            cout << cp.front() << " ";
            cp.pop();
        }
        cout << endl;
    }
};

int main(){
    Stack st = Stack();
    st.printStack();
    st.push(1);
    st.printStack();
    st.push(2);
    st.printStack();
    st.push(3);
    st.printStack();
    st.push(4);
    st.printStack();
    st.push(5);
    st.printStack();
    cout << st.pop() << " is popped from the stack" << endl;
    st.printStack();
    cout << "Top of the stack is: " << st.returnTop() << endl;
    cout << "Size of the stack is: " << st.returnSize() << endl;
    return 0;
}