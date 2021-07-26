/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Foo {
 public:
  Foo() : state(0) {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    state = 1;
    std::lock_guard<std::mutex> lk(state_mtx);
    state_cv.notify_all();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lk(state_mtx);
    state_cv.wait(lk, [&] {
      return state == 1;
    });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    state = 2;
    state_cv.notify_all();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> state_lk(state_mtx);
    state_cv.wait(state_lk, [&] {
      return state == 2;
    });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  int state;
  std::mutex state_mtx;
  std::condition_variable state_cv;
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.(), );
  return 0;
}
