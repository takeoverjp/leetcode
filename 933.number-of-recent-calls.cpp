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
    for (auto it = requests_.begin(); it != requests_.end();) {
      if (*it < t - 3000) {
        it = requests_.erase(it);
      } else {
        break;
      }
    }
    requests_.push_back(t);
    return requests_.size();
  }

 private:
  std::vector<int> requests_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
