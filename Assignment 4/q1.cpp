#include <iostream>

using namespace std;

bool isFull(int rear, int maxqueue) {
    return (rear == maxqueue - 1);
}

bool isEmpty(int front, int rear) {
    return (front == -1 || front > rear);
}

void enqueue(int queue[], int &front, int &rear, int maxqueue) {
    if (isFull(rear, maxqueue)) {
        cout << "Queue is full (Overflow)" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    int item;
    cout << "Enter the number to be added: ";
    cin >> item;
    rear++;
    queue[rear] = item;
    cout << item << " has been enqueued." << endl;
}

int dequeue(int queue[], int &front, int &rear) {
    if (isEmpty(front, rear)) {
        return -1;
    }
    int item = queue[front];
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    return item;
}

void peek(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "The front element is: " << queue[front] << endl;
}

void display(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue contents: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int maxqueue;
    cout << "Enter maximum queue size: ";
    cin >> maxqueue;

    int *queue = new int[maxqueue];
    int front = -1;
    int rear = -1;
    int choice, item;

    do {
        cout << "\n--- Simple Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. IsEmpty\n";
        cout << "4. IsFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue(queue, front, rear, maxqueue);
                break;
            case 2:
                item = dequeue(queue, front, rear);
                if (item != -1) {
                    cout << "Dequeued item: " << item << endl;
                } else {
                    cout << "Queue is empty (Underflow)" << endl;
                }
                break;
            case 3:
                if (isEmpty(front, rear)) {
                    cout << "The queue is empty." << endl;
                } else {
                    cout << "The queue is not empty." << endl;
                }
                break;
            case 4:
                if (isFull(rear, maxqueue)) {
                    cout << "The queue is full." << endl;
                } else {
                    cout << "The queue is not full." << endl;
                }
                break;
            case 5:
                peek(queue, front, rear);
                break;
            case 6:
                display(queue, front, rear);
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