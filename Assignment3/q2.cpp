#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    char arr[100];
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(char ch) {
        if (!isFull()) {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0'; 
    }
};

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int len = strlen(str);
    Stack s(len);

    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
