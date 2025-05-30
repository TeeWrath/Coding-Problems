#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public: int ele;
    public: ListNode *next;

    public: ListNode(int x) : ele(x) , next(nullptr){}
    
    public: ListNode(int x, ListNode *ptr) : ele(x), next(ptr){}
};

void pushStack(int n, ListNode *top){
    ListNode tmp = ListNode(n, top);
    top = &tmp;
}

void popStack(ListNode *top){
    ListNode *tmp = top;
    top = top->next;
    delete(tmp);

}

int returnTop(ListNode *top){
    if(top == nullptr) return -1;
    return top->ele;
}

int main(){
    return 0;
}