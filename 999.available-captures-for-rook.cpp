/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numRookCaptures(vector<vector<char>>& board) {
    int rook_x = 0;
    int rook_y = 0;
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if (board[y][x] == 'R') {
          rook_x = x;
          rook_y = y;
          break;
        }
      }
    }
    int ret = 0;
    int directions[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (const auto& dir : directions) {
      int dx = dir[0];
      int dy = dir[1];
      int x = rook_x + dx;
      int y = rook_y + dy;
      while (y >= 0 && y < 8 && x >= 0 && x < 8) {
        char val = board[y][x];
        if (val == 'B') {
          break;
        }
        if (val == 'p') {
          ret++;
          break;
        }
        x += dx;
        y += dy;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<char>> board;

  board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', 'p', '.', '.', '.', '.'},
           {'.', '.', '.', 'R', '.', '.', '.', 'p'},
           {'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', 'p', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'}};
  ASSERT_EQ(s.numRookCaptures(board), 3);

  board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
           {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
           {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
           {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
           {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'}};
  ASSERT_EQ(s.numRookCaptures(board), 0);

  board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', 'p', '.', '.', '.', '.'},
           {'.', '.', '.', 'p', '.', '.', '.', '.'},
           {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', 'B', '.', '.', '.', '.'},
           {'.', '.', '.', 'p', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'}};
  ASSERT_EQ(s.numRookCaptures(board), 3);

  return 0;
}
