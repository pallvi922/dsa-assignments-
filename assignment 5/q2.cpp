#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *head = nullptr, *tail = nullptr;
    int n, x, key;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for(int i=0;i<n;i++){
        cin >> x;
        Node* temp = new Node{x, nullptr};
        if(!head) head = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    cout << "Enter key to delete: ";
    cin >> key;

    Node *curr = head, *prev = nullptr;
    int count = 0;

    while(curr){
        if(curr->data == key){
            count++;
            if(curr == head) head = curr->next;
            else prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    curr = head;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}

