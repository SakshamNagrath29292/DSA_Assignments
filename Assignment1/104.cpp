#include <iostream>
using namespace std;
void array_input(int arr[], int &size)
{
    cout << "Enter the number of elements in array";
    cin >> size;
    cout << endl;
    cout << "Enter the elements:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void display_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void Reverse_array(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
int main()
{
    int n;
    int arr[100];
    array_input(arr, n);
    cout << endl;
    cout << "The array is";
    display_array(arr, n);
    cout << endl;
    Reverse_array(arr, n);
    cout << "The reversed array is:";
    display_array(arr, n);
}
