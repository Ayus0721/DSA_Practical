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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << ".\n";
    }

    // Remove from the beginning
    void removeFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Removed " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // Remove from a specific position
    void removeFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (position == 0) {
            removeFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Position out of bounds.\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Removed " << nodeToDelete->data << " from position " << position << ".\n";
        delete nodeToDelete;
    }

    // Search for an element
    Node* search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Element " << value << " found.\n";
                return temp;
            }
            temp = temp->next;
        }
        cout << "Element " << value << " not found.\n";
        return nullptr;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtPosition(30, 1);
    list.display();
    list.search(10);
    list.removeFromBeginning();
    list.display();
    list.removeFromPosition(1);
    list.display();
    return 0;
}
