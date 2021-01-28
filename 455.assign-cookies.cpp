/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());
    int cookie_num = s.size();
    int child_num = g.size();
    int ret = 0;
    for (int i = 0; i < child_num; i++) {
      for (int j = 0; j < cookie_num; j++) {
        // cout << g[i] << "," << s[j] << "," << ret << endl;
        if (g[i] <= s[j]) {
          ret++;
          s[j] = -1;
          break;
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> greed;
  vector<int> size;

  greed = {1, 2, 3};
  size = {1, 1};
  assert(s.findContentChildren(greed, size) == 1);

  greed = {1, 2, 3};
  size = {1, 2};
  assert(s.findContentChildren(greed, size) == 2);

  greed = {1, 2, 3};
  size = {3};
  assert(s.findContentChildren(greed, size) == 1);

  greed = {1, 2};
  size = {1, 2, 3};
  assert(s.findContentChildren(greed, size) == 2);

  greed = {1, 2, 3};
  size = {};
  assert(s.findContentChildren(greed, size) == 0);

  greed = {};
  size = {1, 2};
  assert(s.findContentChildren(greed, size) == 0);

  greed = {};
  size = {};
  assert(s.findContentChildren(greed, size) == 0);

  greed = {10, 9, 8, 7};
  size = {5, 6, 7, 8};
  assert(s.findContentChildren(greed, size) == 2);

  return 0;
}
