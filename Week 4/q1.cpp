// Assumptions: all array elements are integer values, and have an upperbound of 2^31 - 1.
// example: nums = [3, 2, 1, 5, 6, 4], number of inversions = 5.

#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

i64 inversions_count;
void merge(vector<int>& arr, int l, int r)
{
    if (r - l < 2)
        return;
    
    vector<int> tmp;
    int mid = l + (r - l) / 2, i = l, j = mid;

    while (i < mid && j < r)
    {
        if (arr[i] <= arr[j])
        {
            tmp.push_back(arr[i]);
            ++i;
        }

        else
        {
            tmp.push_back(arr[j]);
            inversions_count += mid - i;
            ++j;
        }
    }

    while (i < mid)
    {
        tmp.push_back(arr[i]);
        ++i;
    }

    while (j < r)
    {
        tmp.push_back(arr[j]);
        ++j;
    }

    j = 0;
    for (i = l; i < r; ++i)
    {
        arr[i] = tmp[j];
        ++j;
    }
}

void mergeSort(vector<int>& arr, int l, int r)
{
    if (r - l < 2)
        return;
    
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid, r);
    merge(arr, l, r);
}

int main()
{
    // file IO
    freopen("input1.txt", "r", stdin);

    int n;
    cin>>n;

    vector<int> nums(n);
    for (int& i : nums)
        cin>>i;
    
    vector<int> arr(nums);
    inversions_count = 0;
    mergeSort(arr, 0, n);

    cout<<"\nThere are "<<inversions_count<<" inversions in this array.\n";
    return 0;
}

// Time complexity: O(n log n).
// Space complexity: O(n) auxiliary space.