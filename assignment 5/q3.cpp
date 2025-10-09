#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *head = nullptr, *tail = nullptr;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        Node* temp = new Node;
        temp->data = x;
        temp->next = nullptr;

        if(head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node *slow = head;
    Node *fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;
    return 0;
}
