/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class MyQueue {
 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {vec.push_back(x);}

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
      int ret = peek();
      vec.erase(vec.begin());
      return ret;
  }

  /** Get the front element. */
  int peek() {return vec.front();}

  /** Returns whether the queue is empty. */
  bool empty() {return vec.empty();}

  private:
  vector<int> vec;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
  MyQueue q;
  q.push(1);
  q.push(2);
  assert(!q.empty());
  assert(q.peek() == 1);
  assert(q.pop() == 1);
  assert(!q.empty());
  assert(q.peek() == 2);
  assert(q.pop() == 2);
  assert(q.empty());
  return 0;
}
