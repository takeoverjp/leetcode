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
    for (const int command : commands) {
      switch (command) {
        case -2:
          turnLeft();
          break;
        case -1:
          turnRight();
          break;
        default:
          moveForward(command, obstacles);
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
  void updateDistance() { distance_ = max(distance_, x_ * x_ + y_ * y_); }
  void moveForward(const int len, const vector<vector<int>>& obstacles) {
    vector<vector<int>> filtered;
    if (angle_ == Angle::kEast) {
      std::copy_if(
          obstacles.begin(), obstacles.end(), std::back_inserter(filtered),
          [this](const vector<int>& obstacle) { return obstacle[1] == y_; });
      for (int i = 0; i < len; i++) {
        if (findObstacle(x_ + 1, y_, filtered)) {
          return;
        }
        ++x_;
      }
    } else if (angle_ == Angle::kSouth) {
      std::copy_if(
          obstacles.begin(), obstacles.end(), std::back_inserter(filtered),
          [this](const vector<int>& obstacle) { return obstacle[0] == x_; });
      for (int i = 0; i < len; i++) {
        if (findObstacle(x_, y_ - 1, filtered)) {
          return;
        }
        --y_;
      }
    } else if (angle_ == Angle::kWest) {
      std::copy_if(
          obstacles.begin(), obstacles.end(), std::back_inserter(filtered),
          [this](const vector<int>& obstacle) { return obstacle[1] == y_; });
      for (int i = 0; i < len; i++) {
        if (findObstacle(x_ - 1, y_, filtered)) {
          return;
        }
        --x_;
      }
    } else if (angle_ == Angle::kNorth) {
      std::copy_if(
          obstacles.begin(), obstacles.end(), std::back_inserter(filtered),
          [this](const vector<int>& obstacle) { return obstacle[0] == x_; });
      for (int i = 0; i < len; i++) {
        if (findObstacle(x_, y_ + 1, filtered)) {
          return;
        }
        ++y_;
      }
    }
  }
  bool findObstacle(const int x, const int y,
                    const vector<vector<int>>& obstacles) {
    for (const auto& obstacle : obstacles) {
      if (obstacle[0] == x && obstacle[1] == y) {
        return true;
      }
    }
    return false;
  }

  Angle angle_;
  int x_;
  int y_;
  int distance_;
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
