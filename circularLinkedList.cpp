#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    // Insert an element
    void insert(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Inserted " << value << " into the list.\n";
    }

    // Remove an element
    void remove(int value) {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* current = tail->next;
        Node* prev = tail;
        do {
            if (current->data == value) {
                if (current == tail) {
                    if (tail->next == tail) {
                        tail = nullptr;
                    } else {
                        prev->next = tail->next;
                        tail = prev;
                    }
                } else {
                    prev->next = current->next;
                }
                cout << "Removed " << value << " from the list.\n";
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);
        cout << "Element " << value << " not found in the list.\n";
    }

    // Search for an element
    Node* search(int value) {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return nullptr;
        }
        Node* current = tail->next;
        do {
            if (current->data == value) {
                cout << "Element " << value << " found.\n";
                return current;
            }
            current = current->next;
        } while (current != tail->next);
        cout << "Element " << value << " not found.\n";
        return nullptr;
    }

    // Display the list
    void display() {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to start)\n";
    }
};

int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.remove(20);
    list.display();
    list.search(30);
    return 0;
}
