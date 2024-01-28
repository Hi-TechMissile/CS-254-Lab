#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

struct statics
{
    i64 max_subarray_sum; 
    i64 max_prefix; 
    i64 max_suffix; 
    i64 total_sum; 
}; 

// This function returns the maximum sum subarray's statistics, including maximum prefix, maximum suffix and total sum of it.
statics maxSubarray(vector<int>& arr, int l, int r)
{
    if(r - l == 1) 
    {
        return {arr[l], arr[l], arr[l], arr[l]}; 
    }

    int mid = l + (r - l) / 2; 
    statics left = maxSubarray(arr, l, mid); 
    statics right = maxSubarray(arr, mid, r); 
    statics result;  
    result.max_subarray_sum = max({left.max_subarray_sum, right.max_subarray_sum, left.max_suffix + right.max_prefix}); 
    result.max_prefix = max({left.max_prefix, left.total_sum + right.max_prefix}); 
    result.max_suffix = max({right.max_suffix, right.total_sum + left.max_suffix}); 
    result.total_sum = left.total_sum + right.total_sum;  
    return result;
}

int main()
{
    // file IO
    freopen("input2.txt", "r", stdin);

    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  
    {
        cin>>arr[i]; 
    }

    cout<<"\nInput taken from input1.txt. Execution in process...\n";
    statics result = maxSubarray(arr, 0, n); 
    cout<<"Maximum subarray total_sum of the array is: "; 
    cout<<result.max_subarray_sum<<"\n";  

    return 0;
}

// Recurrence: T(n) = 2T(n/2) + theta(1)
// Time complexity: O(n ^ (log_b a) = O(n) by master's theorem
// Space complexity: 4 * log n = O(log n) as four variables are stored per subsegment, the length of which decreases by a factor of 2