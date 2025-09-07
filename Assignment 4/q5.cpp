#include <iostream>

using namespace std;

#define MAX_SIZE 100

void enqueue(int queue[], int &front, int &rear, int &size, int item) {
    if (size == MAX_SIZE) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
    size++;
}

int dequeue(int queue[], int &front, int &rear, int &size) {
    if (size == 0) return -1;
    int item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    size--;
    return item;
}

void stackPush(int item,
               int queue1[], int &front1, int &rear1, int &size1,
               int queue2[], int &front2, int &rear2, int &size2) {
    enqueue(queue2, front2, rear2, size2, item);
    while (size1 > 0) {
        enqueue(queue2, front2, rear2, size2, dequeue(queue1, front1, rear1, size1));
    }
    swap(queue1, queue2);
    swap(front1, front2);
    swap(rear1, rear2);
    swap(size1, size2);
}

int stackPop(int queue1[], int &front1, int &rear1, int &size1) {
    if (size1 == 0) return -1;
    return dequeue(queue1, front1, rear1, size1);
}

void displayStack(int queue[], int front, int rear, int size) {
    if (size == 0) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    int i = front;
    int count = 0;
    while (count < size) {
        cout << queue[i] << " ";
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    cout << endl;
}

int main() {
    int queue1[MAX_SIZE], queue2[MAX_SIZE];
    int front1 = -1, rear1 = -1, size1 = 0;
    int front2 = -1, rear2 = -1, size2 = 0;
    int choice, item;

    do {
        cout << "\n--- Stack using Two Queues Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> item;
                stackPush(item, queue1, front1, rear1, size1, queue2, front2, rear2, size2);
                cout << item << " pushed to stack." << endl;
                break;
            case 2:
                item = stackPop(queue1, front1, rear1, size1);
                if (item != -1) cout << "Popped: " << item << endl;
                else cout << "Stack is empty." << endl;
                break;
            case 3:
                displayStack(queue1, front1, rear1, size1);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}