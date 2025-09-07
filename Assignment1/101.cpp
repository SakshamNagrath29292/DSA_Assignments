#include <iostream>
using namespace std;

const int m = 100;
int arr[m];
int n = 0;

void create()
{
    cout << "ENTER THE NUMBER OF ELEMENTS IN THE ARRAY: ";
    cin >> n;

    cout << "ENTER THE ELEMENTS OF THE ARRAY:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void display()
{
    cout << "The elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert()
{
    int pos;
    cout << "ENTER THE POSITION TO ADD THE ELEMENT: ";
    cin >> pos;

    if (pos < 0 || pos > n)
    {
        cout << "INVALID POSITION\n";
        return;
    }

    int num;
    cout << "ENTER THE NUMBER TO BE ADDED: ";
    cin >> num;

    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    n++;
}

void deleteElement()
{
    int pos;
    cout << "ENTER THE POSITION TO DELETE: ";
    cin >> pos;

    if (pos < 0 || pos >= n)
    {
        cout << "INVALID POSITION\n";
        return;
    }

    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "ELEMENT DELETED\n";
}

void searchelement()
{
    int search;
    cout << "ENTER THE ELEMENT TO SEARCH: ";
    cin >> search;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            cout << "Element found at position: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element not found.\n";
}

int main()
{
    int choice;
    do
    {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            deleteElement();
            break;
        case 5:
            searchelement();
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
