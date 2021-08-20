/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string tictactoe(vector<vector<int>>& moves) {
    char tiles[3][3];
    int size = moves.size();
    memset(tiles, 0x0, sizeof(tiles));
    for (int i = 0; i < size; i++) {
      tiles[moves[i][0]][moves[i][1]] = (i % 2) ? -1 : 1;
    }

    int sum = 0;
    for (int i = 0; i < 3; i++) {
      sum = tiles[i][0] + tiles[i][1] + tiles[i][2];
      if (sum == 3) {
        return "A";
      } else if (sum == -3) {
        return "B";
      }
      sum = tiles[0][i] + tiles[1][i] + tiles[2][i];
      if (sum == 3) {
        return "A";
      } else if (sum == -3) {
        return "B";
      }
    }
    sum = tiles[0][0] + tiles[1][1] + tiles[2][2];
    if (sum == 3) {
      return "A";
    } else if (sum == -3) {
      return "B";
    }
    sum = tiles[0][2] + tiles[1][1] + tiles[2][0];
    if (sum == 3) {
      return "A";
    } else if (sum == -3) {
      return "B";
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (tiles[i][j] == 0) {
          return "Pending";
        }
      }
    }

    return "Draw";
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> moves;
  moves = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
  ASSERT_EQ(s.tictactoe(moves), "A");
  moves = {{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
  ASSERT_EQ(s.tictactoe(moves), "B");
  moves = {{0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2},
           {2, 1}, {0, 1}, {0, 2}, {2, 2}};
  ASSERT_EQ(s.tictactoe(moves), "Draw");
  moves = {{0, 0}, {1, 1}};
  ASSERT_EQ(s.tictactoe(moves), "Pending");
  return 0;
}
