#include <iostream>
#include <vector>
using namespace std;

int MAX(vector<int>& a) {
    const int n = a.size();
    int l = 0, u = n - 1, mid;

    if (n < 2) {
        return a.back();
    }

    if (n < 3) {
        return max(*a.begin(), a.back());
    }

    while (l <= u) {
        mid = l + (u - l) / 2;
        if (mid == 0 || mid == n - 1) {
            return a[mid];
        }

        if (a[mid - 1] < a[mid] && a[mid] < a[mid + 1]) {
            // move to the right
            l = ++mid;
        } else if (a[mid - 1] > a[mid] && a[mid] > a[mid + 1]) {
            // move to the left
            u = --mid;
        } else {
            // maximum value found, mid value is the peak amongst its neighbors
            return a[mid];
        }
    }
    return INT_MIN; // default return value in case the maximum value is not found in any case.
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }

    cout << "\nThe maximum value in the given array is " << MAX(a) << ".\n";
    return 0;
}