/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class MyHashMap {
 public:
  /** Initialize your data structure here. */
  MyHashMap() {}

  /** value will always be non-negative. */
  void put(int key, int value) {
    auto& row = map_[key % kHashSize];
    for (auto& pa : row) {
      if (pa.first == key) {
        pa.second = value;
        return;
      }
    }
    row.push_back({key, value});
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    auto& row = map_[key % kHashSize];
    for (const auto& pa : row) {
      if (pa.first == key) {
        return pa.second;
      }
    }
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    auto& row = map_[key % kHashSize];
    for (auto it = row.begin(); it != row.end(); it++) {
      if (it->first == key) {
        row.erase(it);
        return;
      }
    }
  }

 private:
  static const int kHashSize = 100;
  std::vector<std::pair<int, int>> map_[kHashSize];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
