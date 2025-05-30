#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x){
        int s = s1.size();

        // put s1 maal into s2
        for(int i=0; i<s; i++){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x); // push new item into s1, it becomes last in

        // put s2 maal back in s1
        for(int i=0; i<s; i++){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop(){
        int s = s1.top();
        s1.pop();
        return s;
    }

    int peek(){
        return s1.top();
    }

    int empty(){
        return s1.size() == 0;
    }
};