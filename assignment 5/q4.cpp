#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    Node* t = head;
    while(t != nullptr) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *head = nullptr, *tail = nullptr;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        Node* temp = new Node{x, nullptr};
        if(head == nullptr) head = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    cout << "Original List: ";
    display(head);

    Node *prev = nullptr, *curr = head, *next = nullptr;
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    cout << "Reversed List: ";
    display(head);

    return 0;
}
