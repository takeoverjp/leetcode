/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countMatches(vector<vector<string>>& items, string ruleKey,
                   string ruleValue) {
    int key;
    if (ruleKey == "type") {
      key = 0;
    } else if (ruleKey == "color") {
      key = 1;
    } else {
      key = 2;
    }
    return count_if(
        begin(items), end(items),
        [key, &ruleValue](const auto& item) { return item[key] == ruleValue; });
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<string>> items;
  items = {{"phone", "blue", "pixel"},
           {"computer", "silver", "lenovo"},
           {"phone", "gold", "iphone"}};
  ASSERT_EQ(s.countMatches(items, "color", "silver"), 1);
  items = {{"phone", "blue", "pixel"},
           {"computer", "silver", "phone"},
           {"phone", "gold", "iphone"}};
  ASSERT_EQ(s.countMatches(items, "type", "phone"), 2);
  return 0;
}
