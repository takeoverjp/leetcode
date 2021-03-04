/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        int planted = 0;
        bool is_adjacent = false;
        int len = flowerbed.size();
        for (int i = 0; i < len; i++) {
            int is_flower = flowerbed[i];
            if (is_flower) {
                is_adjacent = true;
                continue;
            }
            if (i < len - 1 && flowerbed[i+1]) {
                is_adjacent = true;
            }
            if (!is_flower && !is_adjacent) {
                planted++;
                if (planted >= n) {
                    return true;
                }
                is_adjacent = true;
                continue;
            }
            is_adjacent = false;
        }
        return false;
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> flowerbed = {1,0,0,0,1};
  assert(s.canPlaceFlowers(flowerbed, 1));
  flowerbed = {1,0,0,0,1};
  assert(!s.canPlaceFlowers(flowerbed, 2));
  flowerbed = {1,0,0,0,0,1};
  assert(!s.canPlaceFlowers(flowerbed, 2));
  flowerbed = {1,0,1,0,1,0,1};
  assert(!s.canPlaceFlowers(flowerbed, 0));
  return 0;
}
