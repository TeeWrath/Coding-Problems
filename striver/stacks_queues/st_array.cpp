#include <bits/stdc++.h>
using namespace std;

void printStack(vector<int> &st, int top)
{
    cout << "Current structure of stack" << endl;
    if (top == -1)
        cout << "stack is empty" << endl;
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << st[i] << " ";
        }
        cout << endl;
    }
}

void stackPush(vector<int> &st, int &top, int n)
{
    top++;
    st.push_back(n);
}

void stackPop(vector<int> &st, int &top)
{
    cout << "popped the elemet: " << st[top] << endl;
    top--;
    st.pop_back();
}

int returnTop(vector<int> &st, int top)
{
    cout << "top element: ";
    if (top == -1)
        return 0;
    return st[top];
}

int returnSize(vector<int> &st, int top)
{
    cout << "size of the stack: ";
    if (top == -1)
        return 0;
    return top + 1;
}

int main()
{
    int top = -1;
    vector<int> st;
    printStack(st, top);
    stackPush(st, top, 5);
    printStack(st, top);
    stackPush(st, top, 6);
    printStack(st, top);
    stackPush(st, top, 3);
    printStack(st, top);
    stackPush(st, top, 1);
    printStack(st, top);
    stackPush(st, top, 9);
    printStack(st, top);
    stackPop(st, top);
    printStack(st, top);
    cout << returnTop(st,top) << endl;
    cout << returnSize(st,top) << endl;
    return 0;
}