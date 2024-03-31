#include <bits/stdc++.h>
using namespace std;

struct Job {
    string job_id;
    int deadline;
    int profit;
};

vector<int> jobScheduling(vector<Job>& arr, int n) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.push_back({arr[i].profit, arr[i].deadline});
    }
    sort(v.begin(), v.end(), [](auto& left, auto& right) {
        return (left.second > right.second || (left.second == right.second && left.first > right.first));
    });

    int ans = 0, cnt = 0, j = 0;
    
    // A container that will store all jobs that can be done on a particular day
    priority_queue<int> q;

    // iterate through the last date in reverse order
    for (int i = n; i > 0; --i) {
        while (j < n && v[j].second >= i) {
            // this job fits into the deadline
            q.push(v[j].first);
            ++j;
        }
        if (!q.empty()) {
            ans += q.top(); // the most profitable job
            ++cnt;
            q.pop();    // complete that job and remove it from the queue
        } 
    }
    
    return vector<int>({cnt, ans});
} 

// Time complexity: O(n * logn)
// Space complexity: O(n)
/*
    This is a greedy approach that provides the following schedule. We 
    select the most profitable job that has its deadline on or after the 
    current day using a priority queue, and complete that job. We will iterate through 
    these days in the descending order, and add new jobs into the list
    if they fit into the deadline. Completed jobs will be removed from the priority queue,
    and the queue always stores jobs that can be completed at any point further in the iteration
    (meaning they could be done at any time on or before the current day).

    This algorithm is optimal because if we are not choosing the most profitable job
    on its respective last possible day, then choosing another job to be done on that day
    will lead to lesser profit, while the rest of the jobs done are unaltered. This algorithm 
    ensures that all the profitable jobs are done, while also making sure that they are done as late
    as possible in order to accommodate jobs with stricter deadlines.
*/

int main() {
    // file IO
    freopen("input2.txt", "r", stdin);
    int tt;
    cin >> tt;
    const int T = tt;
    while (tt--) {
        cout << "TEST #" << T - tt << ":\n\n";
        int n;
        cin >> n;

        vector<Job> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].job_id >> v[i].deadline >> v[i].profit;
        }

        vector<int> ans(jobScheduling(v, n));
        int job_count = *ans.begin(), max_profit = ans.back();
        cout << "\nThe maximum profit obtainable is " << max_profit << " by completing " << job_count << " jobs.\n\n";
    }
    return 0;
}