#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    // file IO
    freopen("input2.txt", "r", stdin);

    int m, n;
    cin>>m>>n;

    int first_pointer = 0, second_pointer = 0, result_pointer = 0;
    vector<int> nums1(m), nums2(n), num(n + m);
    for (int first_pointer = 0; first_pointer < m; ++first_pointer)
        cin>>nums1[first_pointer];
    
    for (int first_pointer = 0; first_pointer < n; ++first_pointer)
        cin>>nums2[first_pointer];
    
    while (first_pointer < m && second_pointer < n)
    {
        if (nums1[first_pointer] <= nums2[second_pointer])
        {
            num[result_pointer] = nums1[first_pointer];
            ++first_pointer;
        }

        else 
        {
            num[result_pointer] = nums2[second_pointer];
            ++second_pointer;
        }
        ++result_pointer;
    }

    while (first_pointer < m)
    {
        num[result_pointer] = nums1[first_pointer];
        ++first_pointer;
        ++result_pointer;
    }

    while (second_pointer < n)
    {
        num[result_pointer] = nums2[second_pointer];
        ++second_pointer;
        ++result_pointer;
    }

    cout<<"\nThe median of the two arrays is: ";
    if ((n + m) % 2)
        cout<<num[(n + m) / 2]<<"\n";
    
    else 
        cout<<setprecision(15)<<(long double)(num[(n + m) / 2] + num[(n + m) / 2 - 1]) / 2.0<<"\n";
    
    return 0;
}

// Time complexity: O(n + m).
// Space complexity: O(n + m) auxiliary space.