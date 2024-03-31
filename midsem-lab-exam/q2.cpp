#include <bits/stdc++.h>
using namespace std;

int shift = 0, choice = 0;

// sample function
long double f(int n) {
    // the blackbox implementation of the function can be specified here
    // for the purpose of testing, the following functions have been used
    switch (choice) {
        case 0:
            return -1LL * abs(n - shift) + 2e3;
            break;
        
        case 1:
            return -1LL * (n - shift) * (n - shift) + 520;
            break;
        
        default:
            cout << "\nYour input was invalid.\n";
            break;
    }
    return shift; // default return element if the choice is not specified properly
}

long double MAX(long long n) {
    long long l = 0, u = n, mid;

    if (n < 2) {
        return f(1);
    }

    if (n < 3) {
        return max(f(1), f(2));
    }

    while (l <= u) {
        mid = l + (u - l) / 2;
        if (mid == 0 || mid == n) {
            return f(mid);
        }

        if (f(mid - 1) < f(mid) && f(mid) < f(mid + 1)) {
            // move to the right
            l = ++mid;
        } else if (f(mid - 1) > f(mid) && f(mid) > f(mid + 1)) {
            // move to the left
            u = --mid;
        } else {
            // maximum value found, mid value is the peak amongst its neighbors
            return f(mid);
        }
    }
    return LLONG_MIN; // default return value in case the maximum value is not found in any case.
}

int main() {
    shift = rand() % 10000;
    cout << "\nEnter the function type. 0 for linear and 1 for quadratic: ";
    cin >> choice;

    cout << "\nThe maximum value of f(n) is " << setprecision(6) << MAX(INT_MAX) << ".\n\n";
    return 0;
}