/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class MyStack {
 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) { fqueue.push_back(x);}

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
      int ret = fqueue.back();
      fqueue.pop_back();
      return ret; }

  /** Get the top element. */
  int top() { return fqueue.back(); }

  /** Returns whether the stack is empty. */
  bool empty() { return fqueue.empty(); }

  private:
  vector<int> fqueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
  MyStack s;
  assert(s.empty() == true);
  s.push(1);
  s.push(2);
  assert(s.top() == 2);
  assert(s.pop() == 2);
  assert(s.empty() == false);
  assert(s.pop() == 1);
  assert(s.empty() == true);
  return 0;
}
