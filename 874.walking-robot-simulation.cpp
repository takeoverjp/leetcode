/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  Solution() : angle_(Angle::kNorth), x_(0), y_(0), distance_(0) {}

  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    for (const auto obstacle : obstacles) {
      obs_.insert({obstacle[0], obstacle[1]});
    }
    for (const int command : commands) {
      switch (command) {
        case -2:
          turnLeft();
          break;
        case -1:
          turnRight();
          break;
        default:
          moveForward(command);
          updateDistance();
          break;
      }
    }
    return distance_;
  }

 private:
  enum Angle {
    kNorth,
    kEast,
    kSouth,
    kWest,
  };
  void turnLeft() {
    if (angle_ == Angle::kEast) {
      angle_ = Angle::kNorth;
    } else if (angle_ == Angle::kSouth) {
      angle_ = Angle::kEast;
    } else if (angle_ == Angle::kWest) {
      angle_ = Angle::kSouth;
    } else if (angle_ == Angle::kNorth) {
      angle_ = Angle::kWest;
    }
  }
  void turnRight() {
    if (angle_ == Angle::kEast) {
      angle_ = Angle::kSouth;
    } else if (angle_ == Angle::kSouth) {
      angle_ = Angle::kWest;
    } else if (angle_ == Angle::kWest) {
      angle_ = Angle::kNorth;
    } else if (angle_ == Angle::kNorth) {
      angle_ = Angle::kEast;
    }
  }
  pair<int, int> getNext() {
    if (angle_ == Angle::kEast) {
      return {x_ + 1, y_};
    } else if (angle_ == Angle::kSouth) {
      return {x_, y_ - 1};
    } else if (angle_ == Angle::kWest) {
      return {x_ - 1, y_};
    } else if (angle_ == Angle::kNorth) {
      return {x_, y_ + 1};
    }
    return {0, 0};
  }
  void updateDistance() { distance_ = max(distance_, x_ * x_ + y_ * y_); }
  void moveForward(const int len) {
    for (int i = 0; i < len; i++) {
      const pair<int, int> next = getNext();
      if (findObstacle(next.first, next.second)) {
        return;
      }
      x_ = next.first;
      y_ = next.second;
    }
  }
  bool findObstacle(const int x, const int y) {
    return obs_.find({x, y}) != obs_.end();
  }

  Angle angle_;
  int x_;
  int y_;
  int distance_;
  struct PositionHash {
    size_t operator()(const pair<int, int>& val) const {
      return val.first;
    }
  };
  unordered_set<pair<int, int>, PositionHash> obs_;
};
// @lc code=end

int main() {
  vector<int> commands;
  vector<vector<int>> obstacles;
  {
    Solution s;
    commands = {4, -1, 3};
    obstacles = {};
    ASSERT_EQ(s.robotSim(commands, obstacles), 25);
  }
  {
    Solution s;
    commands = {4, -1, 4, -2, 4};
    obstacles = {{2, 4}};
    ASSERT_EQ(s.robotSim(commands, obstacles), 65);
  }
  return 0;
}
