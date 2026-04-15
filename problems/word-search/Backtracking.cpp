#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 79. 单词搜索
   *
   * 回溯：从每个格子尝试作为起点，按 word 的下标逐字符匹配。
   * 每次匹配成功后向上下左右扩展，并将当前格子临时标记为已访问，
   * 递归返回后再恢复原字符，避免同一条路径重复使用格子。
   */
  bool exist(vector<vector<char>> &board, string word)
  {
    rows_ = (int)board.size();
    cols_ = (int)board[0].size();

    for (int r = 0; r < rows_; r++)
    {
      for (int c = 0; c < cols_; c++)
      {
        if (dfs(board, word, r, c, 0))
        {
          return true;
        }
      }
    }
    return false;
  }

private:
  int rows_ = 0;
  int cols_ = 0;

  bool dfs(vector<vector<char>> &board, const string &word,
           int r, int c, int index)
  {
    if (index == (int)word.size())
    {
      return true;
    }
    if (r < 0 || r >= rows_ || c < 0 || c >= cols_)
    {
      return false;
    }
    if (board[r][c] != word[index])
    {
      return false;
    }

    char saved = board[r][c];
    board[r][c] = '#'; // 标记已访问

    bool found = dfs(board, word, r + 1, c, index + 1) ||
                 dfs(board, word, r - 1, c, index + 1) ||
                 dfs(board, word, r, c + 1, index + 1) ||
                 dfs(board, word, r, c - 1, index + 1);

    board[r][c] = saved; // 回溯恢复
    return found;
  }
};
