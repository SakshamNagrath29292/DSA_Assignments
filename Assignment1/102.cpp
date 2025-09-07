#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int a[100]; 
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    int unique[100]; 
    int k = 0;      

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < k; j++) {
            if (a[i] == unique[j]) break;
        }
        if (j == k) {      
            unique[k] = a[i];
            k++;
        }
    }

    cout << "Array after removing all duplicates: ";
    for (int i = 0; i < k; i++) cout << unique[i] << " ";
    cout << endl;

    return 0;
}
