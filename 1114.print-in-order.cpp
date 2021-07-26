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
  Foo() : is_first_done(false), is_second_done(false) {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    is_first_done = true;
    std::lock_guard<std::mutex> is_first_done_lk(is_first_done_mtx);
    is_first_done_cv.notify_one();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> is_first_done_lk(is_first_done_mtx);
    is_first_done_cv.wait(is_first_done_lk, [&] {
      return is_first_done;
    });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    is_second_done = true;
    std::lock_guard<std::mutex> is_second_done_lk(is_second_done_mtx);
    is_second_done_cv.notify_one();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> is_second_done_lk(is_second_done_mtx);
    is_second_done_cv.wait(is_second_done_lk, [&] {
      return is_second_done;
    });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  bool is_first_done;
  std::mutex is_first_done_mtx;
  std::condition_variable is_first_done_cv;
  bool is_second_done;
  std::mutex is_second_done_mtx;
  std::condition_variable is_second_done_cv;
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.(), );
  return 0;
}
