#include <iostream>
#include <algorithm>
using namespace std;

int partition(int *arr, int l, int r);

int median(int *arr, int l, int r, int k)
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

int partition(int *arr, int l, int r)
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

void quickSort(int *arr, int l, int r)
{
    if (l >= r)
        return;

    int mid = median(arr, l, r, (r - l + 2) / 2);
    int piv = arr[mid], i = l;
    for (int j = l; j < r; ++j)
    {
        if (arr[j] <= piv && j != mid)
        {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    arr[i] = piv;

    quickSort(arr, l, mid);
    quickSort(arr, mid + 1, r);
}

int main()
{
    freopen("input6.txt", "r", stdin);
    int n;
    cin >> n;

    int a[n];
    for (auto &element : a)
    {
        cin >> element;
    }

    cout << "Sorting using Quick Sort...\n";
    quickSort(a, 0, n - 1);

    cout << "The sorted array is:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}

// Time complexity: O(n log(n)) in the average case, O(n^2 log(n)) in the worst case
// Space complexity: O(1) auxiliary space