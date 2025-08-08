#include <iostream>
#include <vector>
using namespace std;
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))
vector<int> arr = {1, 2, 3};

void sosset(int index, int target, int N, vector<int> &sub)
{
    if (index == N)
    {
        if (target == 0)
        {
            for (auto it : sub)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // Include the current element
    sub.push_back(arr[index]);
    sosset(index + 1, target - arr[index], N, sub);

    // Exclude the current element
    sub.pop_back();
    sosset(index + 1, target, N, sub);
}

int main()
{
    fastread();
    int target = 3; // Example target sum
    vector<int> sub;
    int N = arr.size();

    cout << "Subsets with sum " << target << " are:" << endl;
    sosset(0, target, N, sub);

    return 0;
}
