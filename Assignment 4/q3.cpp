#include <iostream>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

void interleaveQueue(queue<int> &q) {
    if (q.size() % 2 != 0) {
        cout << "Queue must have an even number of elements." << endl;
        return;
    }

    stack<int> s;
    int halfSize = q.size() / 2;

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, element;

    cout << "Enter the number of elements (must be even): ";
    cin >> n;

    while (cin.fail() || n <= 0 || n % 2 != 0) {
        cout << "Invalid input. Please enter a positive even number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> n;
    }

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> element;
        while (cin.fail()) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> element;
        }
        q.push(element);
    }

    cout << "Original queue: ";
    printQueue(q);

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    printQueue(q);

    return 0;
}