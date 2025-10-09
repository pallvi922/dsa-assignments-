#include <iostream>
using namespace std;

#define SIZE 50

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int x) {
        if (rear == SIZE - 1)
            cout << "Queue is full\n";
        else {
            if (front == -1)
                front = 0;
            arr[++rear] = x;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        } else {
            return arr[front++];
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }
};

int main() {
    Queue q, firstHalf;
    int n, x;

    cout << "Enter even number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    int half = n / 2;
    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    cout << "Interleaved Queue: ";
    while (!firstHalf.isEmpty()) {
        cout << firstHalf.dequeue() << " ";
        cout << q.dequeue() << " ";
    }

    return 0;
}

