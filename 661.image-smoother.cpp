/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int w = M[0].size();
    int h = M.size();
    vector<vector<int>> ret(h, vector<int>(w, 0));
    for (int x = 0; x < w; x++) {
      for (int y = 0; y < h; y++) {
        //  cout << "x,y = " << x << "," << y << endl;
        int count = 1;
        int64_t sum = M[y][x];
        if (y >= 1) {
          sum += M[y - 1][x];
          ++count;
        }
        if (y <= h - 2) {
          sum += M[y + 1][x];
          ++count;
        }
        if (x >= 1) {
          if (y >= 1) {
            sum += M[y - 1][x - 1];
            ++count;
          }
          if (y <= h - 2) {
            sum += M[y + 1][x - 1];
            ++count;
          }
          sum += M[y][x - 1];
          ++count;
        }
        if (x <= w - 2) {
          if (y >= 1) {
            sum += M[y - 1][x + 1];
            ++count;
          }
          if (y <= h - 2) {
            sum += M[y + 1][x + 1];
            ++count;
          }
          sum += M[y][x + 1];
          ++count;
        }
        ret[y][x] = sum / count;
      }
    }
    return ret;
  }
};
// @lc code=end

// [[2,3,4],[5,6,7],[8,9,10],[11,12,13],[14,15,16]]