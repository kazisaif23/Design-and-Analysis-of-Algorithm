#include <bits/stdc++.h>
using namespace std;

int arr[3] = {1, 2, 3};

void sumofsubset(int index, int target, int N, vector<int> sub)
{
    if (index == N)
    {
        if (target == 0)
        {
            for (int it = 0; it < sub.size(); it++)
            {
                cout << sub[it] << " ";
            }
            cout << "\n";
        }
        return;
    }

    if (arr[index] <= target)
    {
        sub.push_back(arr[index]);
        sumofsubset(index + 1, target - arr[index], N, sub);
        sub.pop_back();
    }

    sumofsubset(index + 1, target, N, sub);
}

int main()
{
    vector<int> sub;
    sumofsubset(0, 3, 3, sub);
    return 0;
}
