#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_CHAR = 26;

void enqueue(char queue[], int &front, int &rear, int max_size, char item) {
    if ((rear + 1) % max_size == front) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % max_size;
    queue[rear] = item;
}

char dequeue(char queue[], int &front, int &rear, int max_size) {
    if (front == -1) return '\0';
    char item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % max_size;
    }
    return item;
}

char getFront(char queue[], int front) {
    if (front == -1) return '\0';
    return queue[front];
}

void findFirstNonRepeating() {
    int charCount[MAX_CHAR] = {0};
    
    char q[1000]; 
    int front = -1, rear = -1, max_size = 1000;

    cout << "Enter a string to process: ";
    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        if (ch < 'a' || ch > 'z') continue;

        charCount[ch - 'a']++;
        if (charCount[ch - 'a'] == 1) {
            enqueue(q, front, rear, max_size, ch);
        }

        while (front != -1 && charCount[getFront(q, front) - 'a'] > 1) {
            dequeue(q, front, rear, max_size);
        }

        cout << "First non-repeating character for string \"" << str.substr(0, i + 1) << "\" is: ";
        if (front != -1) {
            cout << getFront(q, front) << endl;
        } else {
            cout << "-1 (no non-repeating character)" << endl;
        }
    }
}

int main() {
    findFirstNonRepeating();
    return 0;
}