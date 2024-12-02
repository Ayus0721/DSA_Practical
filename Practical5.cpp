#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* array;
    int capacity;

public:
    Queue(int cap) {
        capacity = cap;
        front = size = 0;
        rear = capacity - 1;
        array = new int[cap];
    }

    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
        cout << "Enqueued " << item << ".\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Dequeued " << array[front] << ".\n";
        front = (front + 1) % capacity;
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << array[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
