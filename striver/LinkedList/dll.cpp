#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1, Node *back1)
    {
        this->data = data1;
        this->next = next1;
        this->back = back1;
    }

public:
    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
        this->back = nullptr;
    }
};

void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty List";
        return;
    }
    if (head->next == nullptr)
    {
        cout << head->data;
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *createDll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    if (arr.size() == 1)
        return head;
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node *delHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    free(temp);
    return head;
}

Node *delTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->back->next = nullptr;
    free(temp);
    return head;
}

Node* delKthNode(Node* head, int k){
    if(head == nullptr) return nullptr;

    int cnt = 0;
    Node* kNode = head;
    while(kNode != nullptr){
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }

    if (kNode == nullptr) return head; // K is out of bounds, return original list

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == nullptr && front == nullptr) return nullptr;
    else if(prev == nullptr) return delHead(head);
    else if(front == nullptr) return delTail(head); // FIXED: == instead of =

    prev->next = front;
    front->back = prev;  // FIXED: Ensure `front` is not nullptr before accessing `back`

    kNode->next = nullptr;
    kNode->back = nullptr;
    free(kNode);

    return head;
}

void delNode(Node* temp){
    if(temp == NULL) return;
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
}

Node* insertHead(Node* head, int val){
    Node* newNode = new Node(val, head, nullptr);
    head->back = newNode;
    return newNode;
}

Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL) return insertHead(head,val);
    Node* tail = head;
    while(tail->next != nullptr) tail = tail->next;
    Node* prev = tail->back;
    Node* temp = new Node(val,tail,prev);
    tail->back =  temp;
    prev->next = temp;

    return head;
}

Node* insertBeforeKthEle(Node* head,int ele, int k){
    if(k == 1){
        return insertHead(head, ele);
    }

    Node* kNode = head;
    int cnt =0;

    while(kNode!= NULL){
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }

    Node* prev = kNode->back;
    Node* temp = new Node(ele,kNode,prev);
    kNode->back = temp;
    prev->next = temp;

    return head;
}

void insertBeforeNode(Node* temp, int val){
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = createDll(arr);
    printList(head);
    // head = delHead(head);
    int k; cin >> k;
    // int ele; cin >> ele;
    // head = delTail(head);
    // head = delKthNode(head,k);
    // delNode(head->next->next->next->next->next);
    // head = insertHead(head,k);
    // head = insertBeforeTail(head,k);
    // head = insertBeforeKthEle(head,ele,k);
    insertBeforeNode(head->next->next,k);
    printList(head);
    return 0;
}