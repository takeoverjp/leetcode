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
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child_num = g.size();
    int cookie_num = s.size();
    int i = 0;
    int j = 0;
    while (i < child_num && j < cookie_num) {
      if (g[i] <= s[j]) {
        i++;
      }
      j++;
    }
    return i;
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
