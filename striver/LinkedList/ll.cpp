#include<bits/stdc++.h>
using namespace std;

// Structure for LinkedList
class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* convertArrToLl(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp =  new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Length of Ll
int lenOfLl(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        // cout << temp->data<< endl;
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// Search in Ll
bool checkIfPresent(Node* head, int num){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == num) return true;
        temp = temp->next;
    }

    return false;
}

// Deleting head of the Ll
Node* delHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Deleting tail of the Ll
Node* delTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

// Delete kth element in Ll
Node* delKEle(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 1; Node* temp = head; Node* prev = NULL;
    while(temp!=NULL){
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        cnt++;
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// Insert new head in linkedlist
Node* insertHead(Node* head, int n){
    Node* temp = new Node(n, head);
    return temp;
}

void insertTail(Node* head, int n){
    if(head == nullptr){
        head = new Node(n);
    }
    Node* temp = new Node(n); // points to null

    Node* move = head;
    while(move->next != nullptr){
        move = move->next;
    }
    move->next = temp;
}

Node* insertKthPos(Node* head, int ele, int k){
    // empty LL
    if(head == nullptr){
        if(k == 1) return new Node(ele);
    }

    // Single element LL
    if(head != nullptr && k == 1) return new Node(ele,head);
    int len = lenOfLl(head);
    
    // New tail
    if(k == len +1){
        insertTail(head,ele);
        return head;
    }

    // for other cases
    int cnt =0; Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == (k-1)){
            Node* x = new Node(ele, temp->next);
            temp->next = x;
            break;;
        }
        temp = temp->next;
    }

    return head;
}

int main(){
    vector<int> arr = {6,1,2,3,4,5};
    Node* head = convertArrToLl(arr);

    // Traversal of LL
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;

    // head = delHead(head);
    // head = delTail(head);
    int k; cin >> k;
    int ele; cin >> ele;
    // head = delKEle(head,k);
    // head = insertHead(head,k);
    // insertTail(head,k);
    insertKthPos(head,ele,k);
    temp = head;
    while(temp != nullptr){
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;

    // cout << lenOfLl(head);
    // cout << checkIfPresent(head, 0);
    return 0;
}