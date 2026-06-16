#include <iostream>
using namespace std;


int main()
{
    cout << "=====================array=====================\n" << endl;
    int const capacity = 10;
    int currentSize = 5;
    int arr[capacity] = {1, 2, 3, 4, 5};
    for (int i = 0; i < currentSize; i++)
    {
        cout << arr[i] << " ";
    }

    cout <<"====================enter element========================\n";
    int element;
    cout << "Enter an element to add to the array: ";
    cin >> element;
    cout <<"====================enter index=======================\n";
    int index;
    cin >> index;
    if (index < 0 || index > currentSize || currentSize >= capacity)
    {
        cout << "Invalid index or array is full." << endl;
        return 1;
    }
    for (int i = currentSize; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    currentSize++;
    cout << "Array after insertion: ";
    for (int i = 0; i < currentSize; i++)
    {
        cout << arr[i] << " ";
    }

}
