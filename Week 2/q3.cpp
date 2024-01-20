#include <iostream>
using namespace std;

void merge(int *a, int l, int r)
{
    int j = l;
    for (int i = (l + r) / 2; i < r; ++i)
    {
        int key = a[i], k = i;
        while (k > j && a[k - 1] > key)
        {
            a[k] = a[k - 1];
            --k;
        }
        a[k] = key;
        j = k;
    }
}

void mergeSort(int *a, int l, int r)
{
    if (l > r - 2)
    {
        return;
    }

    mergeSort(a, l, (l + r) / 2);
    mergeSort(a, (l + r) / 2, r);
    merge(a, l, r);
}

int main()
{
    freopen("input3.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n];

    for (auto &element : a)
    {
        cin >> element;
    }

    cout << "Input taken. Execution under process, please wait...\n\n";
    mergeSort(a, 0, n);

    cout << "Array sorted using merge operation is:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}

// Time complexity: O(n^2 * log(n))
// Space complexity: O(1) auxiliary space