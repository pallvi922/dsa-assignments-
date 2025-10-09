#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertAtEnd(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
        return;
    }
    Node* t = head;
    while (t->next != nullptr)
        t = t->next;
    t->next = temp;
}

void insertAfter(int key, int x) {
    Node* t = head;
    while (t != nullptr && t->data != key)
        t = t->next;
    if (t != nullptr) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = t->next;
        t->next = temp;
    }
}

void insertBefore(int key, int x) {
    if (head == nullptr) return;
    if (head->data == key) {
        insertAtBeginning(x);
        return;
    }
    Node* t = head;
    while (t->next != nullptr && t->next->data != key)
        t = t->next;
    if (t->next != nullptr) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = t->next;
        t->next = temp;
    }
}

void deleteAtBeginning() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* t = head;
    while (t->next->next != nullptr)
        t = t->next;
    delete t->next;
    t->next = nullptr;
}

void deleteNode(int key) {
    if (head == nullptr) return;
    if (head->data == key) {
        deleteAtBeginning();
        return;
    }
    Node* t = head;
    while (t->next != nullptr && t->next->data != key)
        t = t->next;
    if (t->next != nullptr) {
        Node* temp = t->next;
        t->next = temp->next;
        delete temp;
    }
}

void searchNode(int key) {
    Node* t = head;
    int pos = 1;
    while (t != nullptr) {
        if (t->data == key) {
            cout << "Node found at position: " << pos << endl;
            return;
        }
        t = t->next;
        pos++;
    }
    cout << "Node not found" << endl;
}

void displayList() {
    Node* t = head;
    if (t == nullptr) {
        cout << "List is empty\n";
        return;
    }
    while (t != nullptr) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int choice, value, key;
    do {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert After Node\n4.Insert Before Node\n";
        cout << "5.Delete at Beginning\n6.Delete at End\n7.Delete Specific Node\n8.Search Node\n9.Display\n10.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: "; cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter key and value: "; cin >> key >> value;
                insertAfter(key, value);
                break;
            case 4:
                cout << "Enter key and value: "; cin >> key >> value;
                insertBefore(key, value);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                cout << "Enter value to delete: "; cin >> value;
                deleteNode(value);
                break;
            case 8:
                cout << "Enter value to search: "; cin >> value;
                searchNode(value);
                break;
            case 9:
                displayList();
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 10);
    return 0;
}
