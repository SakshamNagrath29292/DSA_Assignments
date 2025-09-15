#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(Node* &head) {
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " inserted at the beginning." << endl;
}

void insertAtEnd(Node* &head) {
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

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
    cout << value << " inserted at the end." << endl;
}

void insertInBetween(Node* &head) {
    int targetValue, newValue;
    cout << "Enter the value of the node to insert after: ";
    cin >> targetValue;
    cout << "Enter the new value to insert: ";
    cin >> newValue;

    Node* temp = head;
    while (temp != nullptr && temp->data != targetValue) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with value " << targetValue << " not found." << endl;
    } else {
        Node* newNode = new Node();
        newNode->data = newValue;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << newValue << " inserted after " << targetValue << "." << endl;
    }
}

void deleteFromBeginning(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    int deletedValue = head->data;
    head = head->next;
    delete temp;
    cout << "Deleted " << deletedValue << " from the beginning." << endl;
}

void deleteFromEnd(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Deleted the only node from the list." << endl;
        return;
    }
    Node* secondLast = head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }
    int deletedValue = secondLast->next->data;
    delete secondLast->next;
    secondLast->next = nullptr;
    cout << "Deleted " << deletedValue << " from the end." << endl;
}

void deleteSpecificNode(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    int targetValue;
    cout << "Enter the value of the node to delete: ";
    cin >> targetValue;

    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == targetValue) {
        head = temp->next;
        delete temp;
        cout << "Deleted node with value " << targetValue << "." << endl;
        return;
    }

    while (temp != nullptr && temp->data != targetValue) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with value " << targetValue << " not found." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Deleted node with value " << targetValue << "." << endl;
}

void searchNode(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    int targetValue;
    cout << "Enter the value to search for: ";
    cin >> targetValue;

    Node* temp = head;
    int position = 1;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data == targetValue) {
            cout << "Node with value " << targetValue << " found at position " << position << "." << endl;
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        cout << "Node with value " << targetValue << " not found in the list." << endl;
    }
}

int main() {
    Node* head = nullptr;
    int choice;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert In-Between (After a node)\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1: insertAtBeginning(head); break;
            case 2: insertAtEnd(head); break;
            case 3: insertInBetween(head); break;
            case 4: deleteFromBeginning(head); break;
            case 5: deleteFromEnd(head); break;
            case 6: deleteSpecificNode(head); break;
            case 7: searchNode(head); break;
            case 8: displayList(head); break;
            case 9: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 9);

    return 0;
}