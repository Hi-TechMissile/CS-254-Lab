#include <bits/stdc++.h>
using namespace std;

pair<int, int> getCoords(int curr, int n)
{
    int x = n - 1 - (curr - 1) / n, y = (curr - 1) % n;
    if (x % 2 == n % 2)
        y = n - 1 - y;

    return {x, y};
}

int snakesAndLadders(vector<vector<int>> &board)
{
    const int n = board.size();
    queue<pair<int, int>> q;
    q.push({1, 0});

    int ans = -1;
    bitset<401> vis;
    while (!q.empty())
    {
        int curr = q.front().first, dep = q.front().second;
        q.pop();

        if (curr == n * n)
        {
            ans = dep;
            break;
        }

        if (vis[curr])
            continue;
        vis[curr] = true;

        int x = getCoords(curr, n).first, y = getCoords(curr, n).second;

        while (board[x][y] > 0 && board[x][y] != curr)
        {
            // move to the destination cell
            curr = board[x][y];
        }

        if (curr == n * n)
        {
            ans = dep;
            break;
        }

        int next = curr + 1;
        while (next <= min(n * n, curr + 6))
        {
            if (next != board[x][y])
                q.push({next, dep + 1});
            ++next;
        }
    }

    return ans;
}

int main()
{
    // file IO
    freopen("input2.txt", "r", stdin);
    int test_cases;
    cin >> test_cases;

    cout << "The minimum number of moves required to complete the game is\n"; 
    for (int t = 1; t < test_cases + 1; ++t) {
        int n;
        cin >> n;
        cout << n << "\n";

        vector<vector<int>> board(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> board[i][j];
            
        
        cout << "Test case " << t << ": " << snakesAndLadders(board) << '\n';
    }
    return 0;
}