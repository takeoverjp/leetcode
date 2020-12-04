/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    stack_.push_back(x);
    for (auto it = sorted_.begin(); it != sorted_.end(); ++it) {
      if (x < *it) {
        it = sorted_.insert(it, x);
        return;
      }
    }
    sorted_.push_back(x);
  }

  void pop() {
    int last = *(stack_.end() - 1);
    stack_.pop_back();
    for (auto it = sorted_.begin(); it != sorted_.end(); ++it) {
      if (last == *it) {
        sorted_.erase(it);
        return;
      }
    }
  }

  int top() { return *(stack_.end() - 1); }

  int getMin() { return sorted_[0]; }

 private:
  std::vector<int> stack_;
  std::vector<int> sorted_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main() {
  {
    MinStack s;
    s.push(-2);
    assert(s.top() == -2);
    assert(s.getMin() == -2);
    s.push(-3);
    assert(s.top() == -3);
    assert(s.getMin() == -3);
    s.push(0);
    assert(s.top() == 0);
    assert(s.getMin() == -3);
    s.pop();
    assert(s.top() == -3);
    assert(s.getMin() == -3);
    s.pop();
    assert(s.top() == -2);
    assert(s.getMin() == -2);
    s.pop();
  }
  return 0;
}
