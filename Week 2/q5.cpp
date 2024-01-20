#include <iostream>
using namespace std;

int main()
{
    // file IO
    freopen("input5.txt", "r", stdin);
    // Taking user input

    static int arr[int(1e7)];
    int n = 1e7;
    cout << "Input taken from file `input1.txt`. Execution in process.\n";
    for (int &i : arr)
        cin >> i;

    // Initializing a variable to store the position of the maximum value
    int min_pos = 0;
    for (int i = 1; i < n; ++i)
        if (arr[min_pos] > arr[i])
            min_pos = i;

    // Now the second minimum will be calculated from the the rest of the array
    int second_min = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        // To avoid duplication of the maximum value
        if (i == min_pos)
            continue;

        second_min = min(second_min, arr[i]);
    }

    cout << "The first minimum in this array: " << arr[min_pos] << "\nThe second minimum in this array: " << second_min << "\n";
}

// Time complexity: O(n)
// Space complexity: O(1) auxiliary space