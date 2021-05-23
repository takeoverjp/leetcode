/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
class RecentCounter {
 public:
  RecentCounter() {}

  int ping(int t) {
    requests_.push(t);
    while (requests_.front() < t - 3000) {
      requests_.pop();
    }
    return requests_.size();
  }

 private:
  std::queue<int> requests_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
