#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 greedyKnapsack(vector<int>& w, vector<int>& v, int& W) {
    vector<pair<int, int>> tmp;
    int j = 0;
    for (int& i : w) {
        tmp.push_back({v[j], i});
        ++j;
    }

    // sorting based on the value-to-weight ratio of the items
    sort(tmp.begin(), tmp.end(), [](auto& left, auto& right) {
        if (left.second == right.second || left.first / left.second == right.first / right.second) {
            return left.first > right.first;
        }
        return left.first / left.second > right.first / right.second;
    });

    int w_total = 0;
    i64 v_total = 0;
    for (auto& [vi, wi] : tmp) {
        if (wi + w_total > W) {
            break;
        }
        v_total += vi;
        w_total += wi;
    }
    return v_total;
}
// time complexity: O(n * logn)
// space complexity: O(n)

/*
    This is a greedy strategy that always chooses the locally best possible 
    option which is: to select the item having maximal value-to-weight ratio. 
    However, it does not work for all inputs, as some choices may lead to better
    utilization of the knapsack capacity `W`. A counterexample that demonstrates
    the failure of this greedy approach is: 

    n = 4, W = 5
    weights = [4, 2, 3, 2]
    values = [16, 7, 10, 1]

    Here, preference order according to value-to-weight ratio is:
    16/4 > 7/2 > 10/3 > 1/2

    Hence by the approach, we can just select the first item and get a profit of 16.
    But there exists a better solution using items 2 and 3, getting a profit of 17.
    This example is enough to prove that the greedy approach does not work always.
*/
/***********************************************************************************/

i64 dpKnapsack(vector<int>& w, vector<int>& v, int& W) {
    const int n = w.size();
    vector<vector<i64>> dp(n + 1, vector<i64>(W + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1]) {
                dp[i][j] = max(dp[i][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }

    return dp[n][W];
}
// time complexity: O(n * W)
// space complexity: O(n * W)

// This approach explores all possible ways of filling the knapsack, hence it 
// always provides an optimal solution.
/***********************************************************************************/

int main() {
    // file IO
    freopen("input1.txt", "r", stdin);
    
    int tt;
    cin >> tt;
    const int T = tt;
    while (tt--) {
        cout << "TEST #" << T - tt << ":\n\n";
        int n, weight_limit;
        cin >> n >> weight_limit;
        vector<int> weights(n), values(n);
        for (int& w : weights) {
            cin >> w;
        }

        for (int& v : values) {
            cin >> v;
        }

        cout << "\nThe maximum total cost as obtained by the greedy approach is " << greedyKnapsack(weights, values, weight_limit) << ".\n";
        cout << "The maximum total cost as obtained by an optimal dynamic programming approach is " << dpKnapsack(weights, values, weight_limit) << ".\n";
    }
    return 0;
}