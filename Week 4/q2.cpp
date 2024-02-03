#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int kthElement(vector<int> &nums1, vector<int> &nums2, const int &k)
{
    const int m = nums1.size(), n = nums2.size();
    int l = 0, u = m - 1, mid;

    while (l <= u)
    {
        mid = l + (u - l) / 2;
        int tmp = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
        int cnt = tmp + mid;

        if (cnt == k - 1)
            return nums1[mid];

        if (cnt < k - 1)
            l = ++mid;

        else
            u = --mid;
    }

    l = 0, u = n - 1;
    while (l <= u)
    {
        mid = l + (u - l) / 2;
        int tmp = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
        int cnt = tmp + mid;

        if (cnt == k - 1)
            return nums2[mid];

        if (cnt < k - 1)
            l = ++mid;

        else
            u = --mid;
    }

    return -1;
}

int main()
{
    // file IO
    freopen("input2.txt", "r", stdin);

    int n, m;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int& num : nums1)
        cin >> num;
    
    for (int& num : nums2)
        cin >> num;

    cout << "\nThe median of the two sorted arrays is: ";
    if ((n + m) % 2 != 0)
        cout << kthElement(nums1, nums2, (n + m + 1) / 2) << "\n";
    
    else
        cout << setprecision(15) << (double)(kthElement(nums1, nums2, (n + m) / 2 + 1) + kthElement(nums1, nums2, (n + m) / 2)) / 2 << "\n";
}

// Time complexity: O(log(n) * log(m)) in the worst case
// Space complexity: O(1) - constant space