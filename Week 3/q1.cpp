// Assumption: Both the matrices are square matrices of the same order, n.
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void add(vector<vector<i64>> A, vector<vector<i64>> B, vector<vector<i64>> &C, int split_index)
{
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            C[i][j] = A[i][j] + B[i][j];
}

vector<vector<i64>> multiply(vector<vector<i64>> A, vector<vector<i64>> B)
{
    int col_1 = A[0].size();
    int row_1 = A.size();
    int col_2 = B[0].size();
    int row_2 = B.size();

    if (col_1 != row_2)
    {
        cout << "\nMatrices A and B are incompatible for multiplication.\n";
        return {};
    }

    vector<i64> result_matrix_row(col_2, 0);
    vector<vector<i64>> result_matrix(row_1, result_matrix_row);

    if (col_1 == 1)
        result_matrix[0][0] = A[0][0] * B[0][0];
    else
    {
        int split_index = col_1 / 2;

        vector<i64> row(split_index, 0);
        vector<vector<i64>> res_top_left(split_index, row);
        vector<vector<i64>> res_top_right(split_index, row);
        vector<vector<i64>> res_bottom_left(split_index, row);
        vector<vector<i64>> res_bottom_right(split_index, row);

        vector<vector<i64>> a00(split_index, row);
        vector<vector<i64>> a01(split_index, row);
        vector<vector<i64>> a10(split_index, row);
        vector<vector<i64>> a11(split_index, row);
        vector<vector<i64>> b00(split_index, row);
        vector<vector<i64>> b01(split_index, row);
        vector<vector<i64>> b10(split_index, row);
        vector<vector<i64>> b11(split_index, row);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++)
            {
                a00[i][j] = A[i][j];
                a01[i][j] = A[i][j + split_index];
                a10[i][j] = A[split_index + i][j];
                a11[i][j] = A[i + split_index][j + split_index];
                b00[i][j] = B[i][j];
                b01[i][j] = B[i][j + split_index];
                b10[i][j] = B[split_index + i][j];
                b11[i][j] = B[i + split_index][j + split_index];
            }

        add(multiply(a00, b00), multiply(a01, b10), res_top_left, split_index);
        add(multiply(a00, b01), multiply(a01, b11), res_top_right, split_index);
        add(multiply(a10, b00), multiply(a11, b10), res_bottom_left, split_index);
        add(multiply(a10, b01), multiply(a11, b11), res_bottom_right, split_index);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++)
            {
                result_matrix[i][j] = res_top_left[i][j];
                result_matrix[i][j + split_index] = res_top_right[i][j];
                result_matrix[split_index + i][j] = res_bottom_left[i][j];
                result_matrix[i + split_index] [j + split_index] = res_bottom_right[i][j];
            }

        res_top_left.clear();
        res_top_right.clear();
        res_bottom_left.clear();
        res_bottom_right.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

int main()
{
    // file IO
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int n;
    cin>>n;
    vector<vector<i64>> A(n, vector<i64>(n)), B(n, vector<i64>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin>>A[i][j];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin>>B[i][j];
    }

    

    vector<vector<i64>> result_matrix = /* multiply(A, B); */A;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout<<result_matrix[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}

// Recurrence: T(n) = 8T(n/2) + O(n^2), thus O(n^3) time complexity using master's theorem
// Auxiliary space: O(n ^ 2)