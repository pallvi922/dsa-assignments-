#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    char arr[SIZE];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return (front == -1 || front > rear); }

    void enqueue(char ch) {
        if (rear == SIZE - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = ch;
    }

    void dequeue() {
        if (!isEmpty()) front++;
    }

    char getFront() {
        if (!isEmpty()) return arr[front];
        return '\0';
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int freq[26] = {0};
    Queue q;

    cout << "Output: ";
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        q.enqueue(s[i]);

        while (!q.isEmpty() && freq[q.getFront() - 'a'] > 1)
            q.dequeue();

        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.getFront() << " ";
    }
    return 0;
}
