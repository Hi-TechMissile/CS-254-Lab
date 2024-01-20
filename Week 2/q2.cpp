#include <iostream>
using namespace std;

int main()
{
    freopen("input2.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    int a[n];
    for (auto &element : a)
    {
        cin >> element;
    }

    cout << "Input taken. Execution under process, please wait...\n\n";

    int j = 0;
    for (int i = m; i < n; ++i)
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

    cout << "Sorted array is:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}

// Time Complexity: O(n * (n - m))
// Space Complexity: O(1) auxiliary space