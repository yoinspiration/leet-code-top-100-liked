#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 51. N 皇后
   *
   * 回溯按行放置皇后：每行选择一个合法列。
   * 使用三组标记做 O(1) 冲突检测：
   * - cols[col]：列是否被占用
   * - diag1[row - col + n - 1]：主对角线是否被占用
   * - diag2[row + col]：副对角线是否被占用
   */
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    vector<bool> cols(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);

    backtrack(0, n, board, cols, diag1, diag2, result);
    return result;
  }

private:
  void backtrack(int row, int n,
                 vector<string> &board,
                 vector<bool> &cols,
                 vector<bool> &diag1,
                 vector<bool> &diag2,
                 vector<vector<string>> &result)
  {
    if (row == n)
    {
      result.push_back(board);
      return;
    }

    for (int col = 0; col < n; col++)
    {
      int d1 = row - col + (n - 1);
      int d2 = row + col;
      if (cols[col] || diag1[d1] || diag2[d2])
      {
        continue;
      }

      board[row][col] = 'Q';
      cols[col] = true;
      diag1[d1] = true;
      diag2[d2] = true;

      backtrack(row + 1, n, board, cols, diag1, diag2, result);

      board[row][col] = '.';
      cols[col] = false;
      diag1[d1] = false;
      diag2[d2] = false;
    }
  }
};
