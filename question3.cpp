#include <bits/stdc++.h>
#include <ctime> // for clock()
using namespace std;

// --------- Bubble Sort ----------
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// --------- Quick Sort ----------
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// --------- Main ----------
int main()
{
    const int SIZE = 1000;
    int arr1[SIZE], arr2[SIZE];

    // Generate random numbers
   srand(time(0));
    //int arr[] = {100, 11, 445, 1, 330, 3000, 999};
    for (int i = 0; i < SIZE; i++)
    {
        int num = rand() % 10000;
        arr1[i] = arr2[i] = num;
    }

    // Measure Bubble Sort Time
    clock_t start_bubble = clock();
    bubbleSort(arr1, SIZE);
    clock_t end_bubble = clock();

    // Measure Quick Sort Time
    clock_t start_quick = clock();
    quickSort(arr2, 0, SIZE - 1);
    clock_t end_quick = clock();

    // Time results
    double time_bubble = double(end_bubble - start_bubble) / CLOCKS_PER_SEC;
    double time_quick = double(end_quick - start_quick) / CLOCKS_PER_SEC;

    cout << "Bubble Sort Time: " << time_bubble << " seconds" << endl;
    cout << "Quick Sort Time: " << time_quick << " seconds" << endl;

    return 0;
}
