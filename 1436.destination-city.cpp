/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_set<string> source;
        for(auto& path: paths) {
            source.insert(path[0]);
        }
        for(auto& path: paths) {
            if (source.count(path[1]) == 0){
                return path[1];
            }
        }
        return "";
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<vector<string>> paths;
  paths = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
  ASSERT_EQ(s.destCity(paths), "Sao Paulo");
  paths = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
  ASSERT_EQ(s.destCity(paths), "A");
  paths = {{"A", "Z"}};
  ASSERT_EQ(s.destCity(paths), "Z");
  return 0;
}
