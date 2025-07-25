#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key)
{
    if (left > right)
        return -1; // Key not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, left, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, right, key);
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the number to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in array." << endl;

    return 0;
}
