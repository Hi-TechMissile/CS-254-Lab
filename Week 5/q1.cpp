#include <bits/stdc++.h>
using namespace std;

// Assuming that the largest number of rows and 
// columns we can have is 1000

// WARNING: this code requires more recursion than the default allowed value in G++.
// To compile and run, in a cmd (not PowerShell) terminal, run:
//      g++ -Wl,--stack,268435456 q1.cpp
//      a.exe

vector<bitset<1000>> vis(1000);
vector<string> matrix(1000);
int n, m;

void measureSizeOfRegion(int x, int y, int& curr_size)
{
    // base cases
    if (x > n - 1 || y > m - 1 || x < 0 || y < 0)
        return;

    if (vis[x][y])
        return;
    
    vis[x][y] = true;
    curr_size += (matrix[x][y]);
    for (int delta_x = -1; delta_x < 2; ++delta_x)
        for (int delta_y = -1; delta_y < 2; ++delta_y)
            measureSizeOfRegion(x + delta_x, y + delta_y, curr_size);
        
    
}

int main()
{
    // file IO
    freopen("input1.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> matrix[i];
    
    for (auto& row : vis)
        row.reset();
    
    int largest_size = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int curr_size = 0;
            if (matrix[i][j] == '1')
                measureSizeOfRegion(i, j, curr_size);
            largest_size = max(largest_size, curr_size);
        }
    }

    cout << "The size of the largest region is: " << largest_size << "\n";
    return 0;
}   