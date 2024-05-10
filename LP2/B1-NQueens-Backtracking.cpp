#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void addSolution(vector<vector<string>> &board, vector<vector<string>> &ans) {
        vector<string> temp;
        for (auto row : board)
            temp.push_back(accumulate(row.begin(), row.end(), string("")));
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<string>> &board, int n) {
        // check the column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == "Q")
                return false;
        }

        // check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == "Q")
                return false;
        }

        // check upper right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == "Q")
                return false;
        }

        return true;
    }

    void solve(int row, vector<vector<string>> &ans, vector<vector<string>> &board, int n)
    {
        if (row == n) {
            addSolution(board, ans);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = "Q";
                solve(row + 1, ans, board, n);
                board[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;

        solve(0, ans, board, n);
        return ans;
    }
};

int main() {
    Solution s;
    int n;
    cout<<"Enter size of board: ";
    cin>>n;
    vector<vector<string>> ans = s.solveNQueens(n);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << endl;
        cout << endl;
    }

    return 0;
}