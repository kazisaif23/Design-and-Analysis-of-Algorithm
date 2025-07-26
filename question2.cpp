#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int min, max;
};

Pair findMinMax(int arr[], int low, int high)
{
    Pair result, left, right;

    // If only one element
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If two elements
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // If more than two elements
    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main()
{
    int arr[] = {100, 11, 445, 1, 330, 3000, 999};
    int n = sizeof(arr) / sizeof(arr[0]);

    Pair minmax = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << minmax.min << endl;
    cout << "Maximum element: " << minmax.max << endl;

    return 0;
}
