#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int l, int r);

int median(int arr[], int l, int r, int k)
{
    // Determine the position of the pivot, chosen as arr[r]
    int pos = partition(arr, l, r);

    // If position is same as k
    if (pos - l == k - 1)
        return pos;
    if (pos - l > k - 1) // If position is more, recur towards the left
        return median(arr, l, pos - 1, k);

    // Else recur towards the right
    return median(arr, pos + 1, r, k - pos + l - 1);
}

int partition(int arr[], int l, int r)
{
    int piv = arr[r], i = l;
    for (int j = l; j < r; ++j)
    {
        if (arr[j] <= piv)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[r]);
    return i;
}

int main()
{
    freopen("input4.txt", "r", stdin);
    int n;
    cin >> n;

    int a[n];
    for (auto &element : a)
    {
        cin >> element;
    }

    cout << "The median of the array is: " << a[median(a, 0, n - 1, (n + 1) / 2)] << "\n";
    return 0;
}

// Time complexity: O(n^2) in worst case, O(n) in average case
// Space complexity: O(1) auxiliary space