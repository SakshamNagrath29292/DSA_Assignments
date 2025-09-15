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

int countAndDeleteOccurrences(Node* &head, int key) {
    int count = 0;
    Node* currentNode = head;
    Node* previousNode = nullptr;

    while (currentNode != nullptr) {
        if (currentNode->data == key) {
            count++;
            Node* nodeToDelete = currentNode;
            if (previousNode == nullptr) {
                head = currentNode->next;
                currentNode = head;
            } else {
                previousNode->next = currentNode->next;
                currentNode = currentNode->next;
            }
            delete nodeToDelete;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return count;
}

int main() {
    Node* head = nullptr;
    int numberOfNodes, value, key;

    cout << "Enter the number of nodes to create: ";
    cin >> numberOfNodes;

    for (int i = 0; i < numberOfNodes; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "\nOriginal Linked List: ";
    displayList(head);

    cout << "Enter the key to count and delete: ";
    cin >> key;

    int occurrences = countAndDeleteOccurrences(head, key);

    cout << "\nNumber of occurrences of " << key << ": " << occurrences << endl;
    cout << "Updated Linked List: ";
    displayList(head);

    return 0;
}