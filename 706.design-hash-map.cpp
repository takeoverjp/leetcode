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
  void put(int key, int value) { map_[key] = value; }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    if (map_.count(key) == 0) {
      return -1;
    }
    return map_[key];
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    map_.erase(key);
  }

 private:
  std::map<int, int> map_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
