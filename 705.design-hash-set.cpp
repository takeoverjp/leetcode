/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class MyHashSet {
 public:
  /** Initialize your data structure here. */
  MyHashSet() {}

  void add(int key) { set_.emplace(key); }

  void remove(int key) { set_.erase(key); }

  /** Returns true if this set contains the specified element */
  bool contains(int key) { return set_.count(key); }

 private:
  std::unordered_set<int> set_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
