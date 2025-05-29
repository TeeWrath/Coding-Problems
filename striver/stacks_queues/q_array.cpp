#include<bits/stdc++.h>
using namespace std;

void printQueue(vector<int> &qu, int top){
    if(top == qu.size()){
        cout << "Empty queue" << endl;
    }
    else{
        for(int i =top; i<qu.size(); i++){
            cout << qu[i] << " ";
        }
        cout << endl;
    }
}

void queuePush(vector<int> &qu, int n, int top)
{
    cout << "Pushed in the queue: " << n << endl;
    qu.push_back(n);
    printQueue(qu,top);
}

void queuePop(vector<int> &qu, int &top){
    cout << "Popped the element: " << qu[top] << endl;
    top++;
    printQueue(qu,top);
}

int returnQuTop(int top, vector<int> &qu){
    if(top == -1|| top == qu.size()) return 0;
    cout << "Top element: " << qu[top] << endl;
    return qu[top];
}

int returnQuSize(vector<int> &qu, int top){
    if(top == -1 || top == qu.size()) return 0;
    return qu.size() - top;

}

int main(){
    vector<int> qu;
    int top=0;

    queuePush(qu,5,top);
    queuePush(qu,6,top);
    queuePush(qu,3,top);
    queuePush(qu,1,top);
    queuePush(qu,9,top);
    queuePop(qu,top);
    cout << returnQuTop(top,qu) << endl;
    cout << returnQuSize(qu,top) << endl;
    queuePop(qu,top);
    queuePop(qu,top);
    queuePop(qu,top);
    queuePop(qu,top);
    cout << returnQuTop(top,qu) << endl;
    cout << returnQuSize(qu,top) << endl;
    return 0;
}