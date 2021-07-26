/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
// #define USE_PROMISE
#if defined(USE_PROMISE)
class Foo {
 public:
  Foo() {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    promises_[0].set_value();
  }

  void second(function<void()> printSecond) {
    promises_[0].get_future().wait();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    promises_[1].set_value();
  }

  void third(function<void()> printThird) {
    promises_[1].get_future().wait();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  std::promise<void> promises_[2];
};
#else
class Foo {
 public:
  Foo() : state_(0) {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    std::lock_guard<std::mutex> lk(state_mtx_);
    state_ = 1;
    state_cvs_[0].notify_one();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lk(state_mtx_);
    state_cvs_[0].wait(lk, [this]() { return state_ == 1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    state_ = 2;
    state_cvs_[1].notify_one();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> lk(state_mtx_);
    state_cvs_[1].wait(lk, [this]() { return state_ == 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  uint8_t state_;
  std::mutex state_mtx_;
  std::condition_variable state_cvs_[2];
};
#endif
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.(), );
  return 0;
}
