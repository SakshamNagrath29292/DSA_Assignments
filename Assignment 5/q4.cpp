#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void reverseList(Node* &head) {
    Node* previousNode = nullptr;
    Node* currentNode = head;
    Node* nextNode = nullptr;

    while (currentNode != nullptr) {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    head = previousNode;
}

int main() {
    Node* head = nullptr;
    int numberOfNodes, value;

    cout << "Enter the number of nodes to create: ";
    cin >> numberOfNodes;

    for (int i = 0; i < numberOfNodes; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "\nOriginal List: ";
    displayList(head);

    reverseList(head);

    cout << "Reversed List: ";
    displayList(head);

    return 0;
}