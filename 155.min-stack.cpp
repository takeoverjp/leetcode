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
  MinStack() : min_(INT32_MAX) {}

  void push(int x) {
    if (x <= min_) {
      stack_.push(min_);
      min_ = x;
    }
    stack_.push(x);
  }

  void pop() {
    int top = stack_.top();
    stack_.pop();
    if (top != min_) {
      return;
    }
    min_ = stack_.top();
    stack_.pop();
  }

  int top() { return stack_.top(); }

  int getMin() { return min_; }

 private:
  int min_;
  std::stack<int> stack_;
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
  {
    MinStack s;
    s.push(0);
    s.push(1);
    s.push(0);
    assert(s.getMin() == 0);
    s.pop();
    assert(s.getMin() == 0);
  }
  return 0;
}
