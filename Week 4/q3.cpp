#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int l, int r)
{
    int piv = nums[r], i = l;
    for (int j = l; j < r; ++j)
    {
        if (nums[j] >= piv)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }

    swap(nums[i], nums[r]);
    return i;
}

int k_thLargest(vector<int>& nums, int l, int r, int k)
{
    // Determine the position of the pivot, chosen as nums[r]
    int pos = partition(nums, l, r);

    // If position is same as k
    if (pos - l == k - 1)
        return nums[pos];
    if (pos - l > k - 1) // If position is more, recur towards the left
        return k_thLargest(nums, l, pos - 1, k);

    // Else recur towards the right
    return k_thLargest(nums, pos + 1, r, k - pos + l - 1);
}

int main()
{
    // file IO
    freopen("input3.txt", "r", stdin);

    int n, k;
    cin>>n>>k;

    if (k > n)
    {
        cout<<"k must be less than n.\n\nRejected and terminated.\n";
        return 0;
    }

    vector<int> nums(n);
    for (int& i : nums)
        cin>>i;
    
    cout<<"\nk = "<<k<<"\nThe k-th largest element of the array is: "<<k_thLargest(nums, 0, n - 1, k)<<"\n";
    return 0;
}

// Time complexity: O(n) in the average case, O(n^2) in the worst case.
// Space complexity: Constant space.