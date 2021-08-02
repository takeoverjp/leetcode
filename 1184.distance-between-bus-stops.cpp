/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    int total = accumulate(distance.begin(), distance.end(), 0);
    int s = min(start, destination);
    int e = max(start, destination);
    int sum = 0;
    for (int i = s; i < e; i++) {
      sum += distance[i];
    }
    return min(sum, total - sum);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> distance;
  distance = {1, 2, 3, 4};
  ASSERT_EQ(s.distanceBetweenBusStops(distance, 0, 1), 1);
  ASSERT_EQ(s.distanceBetweenBusStops(distance, 0, 2), 3);
  ASSERT_EQ(s.distanceBetweenBusStops(distance, 0, 3), 4);
  return 0;
}
