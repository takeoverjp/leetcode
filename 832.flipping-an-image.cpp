/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */
#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int n = image.size();
    for (auto& row : image) {
      for (int i = 0; i <= (n - 1) / 2; i++) {
        if (i == n - i - 1) {
          row[i] = !row[i];
        } else {
          int tmp = row[i];
          row[i] = !row[n - i - 1];
          row[n - i - 1] = !tmp;
        }
      }
    }
    return image;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> image;
  vector<vector<int>> exp;
  image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
  exp = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  assert(s.flipAndInvertImage(image) == exp);
  image = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
  exp = {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}};
  assert(s.flipAndInvertImage(image) == exp);
  return 0;
}
