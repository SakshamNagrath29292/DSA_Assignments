#include <iostream>
#include <limits> // Required for numeric_limits

using namespace std;

bool isFull(int front, int rear, int maxqueue) {
    return ((rear + 1) % maxqueue == front);
}

bool isEmpty(int front) {
    return (front == -1);
}

void enqueue(int queue[], int &front, int &rear, int maxqueue) {
    if (isFull(front, rear, maxqueue)) {
        cout << "Queue is full (Overflow)" << endl;
        return;
    }
    int item;
    cout << "Enter the number to be added: ";
    cin >> item;

    // Input validation for the item to be enqueued
    while (cin.fail()) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> item;
    }

    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % maxqueue;
    queue[rear] = item;
    cout << item << " has been enqueued." << endl;
}

int dequeue(int queue[], int &front, int &rear, int maxqueue) {
    if (isEmpty(front)) {
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % maxqueue;
    }
    return item;
}

void peek(int queue[], int front) {
    if (isEmpty(front)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "The front element is: " << queue[front] << endl;
}

void display(int queue[], int front, int rear, int maxqueue) {
    if (isEmpty(front)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue contents: ";
    int i = front;
    while (i != rear) {
        cout << queue[i] << " ";
        i = (i + 1) % maxqueue;
    }
    cout << queue[rear] << endl;
}

int main() {
    int maxqueue;
    cout << "Enter maximum queue size: ";
    cin >> maxqueue;
     while (cin.fail() || maxqueue <= 0) {
        cout << "Invalid input. Please enter a positive number for the size: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> maxqueue;
    }


    int *queue = new int[maxqueue];
    int front = -1;
    int rear = -1;
    int choice, item;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. IsEmpty\n";
        cout << "4. IsFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // This block handles bad input for the menu choice
        if (cin.fail()) {
            cout << "Invalid choice. Please enter a number from the menu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0; // Set a non-exit choice to continue the loop
            continue;
        }

        switch (choice) {
            case 1:
                enqueue(queue, front, rear, maxqueue);
                break;
            case 2:
                item = dequeue(queue, front, rear, maxqueue);
                if (item != -1) {
                    cout << "Dequeued item: " << item << endl;
                } else {
                    cout << "Queue is empty (Underflow)" << endl;
                }
                break;
            case 3:
                if (isEmpty(front)) {
                    cout << "The queue is empty." << endl;
                } else {
                    cout << "The queue is not empty." << endl;
                }
                break;
            case 4:
                if (isFull(front, rear, maxqueue)) {
                    cout << "The queue is full." << endl;
                } else {
                    cout << "The queue is not full." << endl;
                }
                break;
            case 5:
                peek(queue, front);
                break;
            case 6:
                display(queue, front, rear, maxqueue);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 7);

    delete[] queue;
    return 0;
}