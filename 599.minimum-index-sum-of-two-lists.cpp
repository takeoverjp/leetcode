/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> ret;
    int len1 = list1.size();
    int len2 = list2.size();
    for (int idx_sum = 0; idx_sum < len1 + len2; idx_sum++) {
      for (int idx2 = 0; idx2 < len2 && idx2 <= idx_sum; idx2++) {
        int idx1 = idx_sum - idx2;
        if (idx1 >= len1) {
          continue;
        }
        if (list1[idx1] == list2[idx2]) {
          ret.push_back(list1[idx1]);
        }
      }
      if (ret.size()) {
        return ret;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> list1, list2, exp;
  list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse",
           "Shogun"};
  exp = {"Shogun"};
  assert(s.findRestaurant(list1, list2) == exp);

  list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  list2 = {"KFC", "Shogun", "Burger King"};
  exp = {"Shogun"};
  assert(s.findRestaurant(list1, list2) == exp);

  list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  list2 = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
  exp = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
  assert(s.findRestaurant(list1, list2) == exp);

  list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  list2 = {"KNN", "KFC", "Burger King", "Tapioca Express", "Shogun"};
  exp = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
  assert(s.findRestaurant(list1, list2) == exp);

  list1 = {"KFC"};
  list2 = {"KFC"};
  exp = {"KFC"};
  assert(s.findRestaurant(list1, list2) == exp);

  list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  list2 = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
  exp = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
  assert(s.findRestaurant(list1, list2) == exp);

  return 0;
}
