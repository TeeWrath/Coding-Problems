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
    head = delKEle(head,k);
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