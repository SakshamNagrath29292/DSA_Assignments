#include <iostream>
using namespace std;

bool checkEmpty(int frontIndex, int backIndex) {
    return (frontIndex == -1 || frontIndex > backIndex);
}

bool checkFull(int backIndex, int maxSize) {
    return (backIndex == maxSize - 1);
}

int removeElement(int arr[], int &frontIndex, int &backIndex) {
    if (checkEmpty(frontIndex, backIndex)) {
        return -1;
    }
    int element = arr[frontIndex];
    frontIndex++;
    if (frontIndex > backIndex) {
        frontIndex = -1;
        backIndex = -1;
    }
    return element;
}

void insertElement(int arr[], int &frontIndex, int &backIndex, int maxSize) {
    if (checkFull(backIndex, maxSize)) {
        cout << "Queue overflow! Cannot insert." << endl;
        return;
    }
    if (frontIndex == -1) {
        frontIndex = 0;
    }
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;
    backIndex++;
    arr[backIndex] = value;
}

void showFront(int arr[], int frontIndex, int backIndex) {
    if (checkEmpty(frontIndex, backIndex)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front element: " << arr[frontIndex] << endl;
}

void showQueue(int arr[], int frontIndex, int backIndex) {
    if (checkEmpty(frontIndex, backIndex)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = frontIndex; i <= backIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int capacity;
    cout << "Enter maximum size of queue: ";
    cin >> capacity;

    int *arr = new int[capacity];
    int frontIndex = -1, backIndex = -1;
    int option, element;

    do {
        cout << "\n--- Queue Operations Menu ---\n";
        cout << "1. Insert (Enqueue)\n";
        cout << "2. Remove (Dequeue)\n";
        cout << "3. Check Empty\n";
        cout << "4. Check Full\n";
        cout << "5. Show Front\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                insertElement(arr, frontIndex, backIndex, capacity);
                break;
            case 2:
                element = removeElement(arr, frontIndex, backIndex);
                if (element != -1)
                    cout << "Removed: " << element << endl;
                else
                    cout << "Queue underflow! Nothing to remove." << endl;
                break;
            case 3:
                if (checkEmpty(frontIndex, backIndex))
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;
            case 4:
                if (checkFull(backIndex, capacity))
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                break;
            case 5:
                showFront(arr, frontIndex, backIndex);
                break;
            case 6:
                showQueue(arr, frontIndex, backIndex);
                break;
            case 7:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }
    } while (option != 7);

    delete[] arr;
    return 0;
}
