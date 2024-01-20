#include <iostream>
using namespace std;

int main()
{
    freopen("input1.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    int A[n], B[m], Union[n + m], Intersection[min(n, m)], C[n + m];
    for (int &element : A)
    {
        cin >> element;
    }

    for (int &element : B)
    {
        cin >> element;
    }

    cout << "Input taken. Execution under process.\nPlease wait...\n\n";
    int j = 0, i = 0, curr_size = 0;

    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            C[curr_size] = A[i];
            ++i;
        }
        else
        {
            C[curr_size] = B[j];
            ++j;
        }
        ++curr_size;
    }

    while (i < n)
    {
        C[curr_size] = A[i];
        ++curr_size;
        ++i;
    }

    while (j < m)
    {
        C[curr_size] = B[j];
        ++curr_size;
        ++j;
    }

    curr_size = 0;
    Union[0] = C[curr_size];
    ++curr_size;

    for (int i = 1; i < n + m; ++i)
    {
        if (C[i] != C[i - 1])
        {
            Union[curr_size] = C[i];
            ++curr_size;
        }
    }

    cout << "(a) The merged array C:\n";
    for (int &element : C)
    {
        cout << element << " ";
    }
    cout << "\n";

    cout << "(b) The sorted array/set A U B:\n";
    for (int i = 0; i < curr_size; ++i)
    {
        cout << Union[i] << " ";
    }
    cout << "\n";

    curr_size = 0;
    i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            ++i;
        }
        else if (A[i] > B[j])
        {
            ++j;
        }
        else
        {
            Intersection[curr_size++] = A[i];
            ++i;
            ++j;
        }
    }

    cout << "(c) The intersection of the arrays A and B is:\n";
    for (int i = 0; i < curr_size; ++i)
    {
        cout << Intersection[i] << " ";
    }
    cout << "\n";
    return 0;
}

// Time Complexity: 
// (a) O(n + m)
// (b) O(n + m)
// (c) O(n + m)

// Space complexity:
// (a) O(n + m) auxiliary space
// (b) O(n + m) auxiliary space
// (c) O(min(n, m)) auxiliary space