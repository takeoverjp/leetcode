/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    int origColor = image[sr][sc];
    if (origColor == newColor) {
      return image;
    }
    image[sr][sc] = newColor;
    floodFill(image, sr - 1, sc, newColor, origColor);
    floodFill(image, sr + 1, sc, newColor, origColor);
    floodFill(image, sr, sc - 1, newColor, origColor);
    floodFill(image, sr, sc + 1, newColor, origColor);
    return image;
  }

 private:
  void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor,
                 int origColor) {
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
      return;
    }
    int myColor = image[sr][sc];
    if (myColor != origColor || myColor == newColor) {
      return;
    }
    image[sr][sc] = newColor;
    floodFill(image, sr - 1, sc, newColor, origColor);
    floodFill(image, sr + 1, sc, newColor, origColor);
    floodFill(image, sr, sc - 1, newColor, origColor);
    floodFill(image, sr, sc + 1, newColor, origColor);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> image, exp;

  image = {{1}};
  exp = {{2}};
  assert(s.floodFill(image, 0, 0, 2) == exp);

  image = {{1, 0, 1}};
  exp = {{1, 0, 2}};
  assert(s.floodFill(image, 0, 2, 2) == exp);

  image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  exp = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  assert(s.floodFill(image, 1, 1, 1) == exp);

  image = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}};
  exp = {{2, 0, 0}, {2, 0, 0}, {2, 0, 0}};
  assert(s.floodFill(image, 2, 0, 2) == exp);

  image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  exp = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
  assert(s.floodFill(image, 1, 1, 2) == exp);
  return 0;
}
