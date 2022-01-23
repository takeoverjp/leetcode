/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
 public:
  ParkingSystem(int big, int medium, int small)
      : big_(big), medium_(medium), small_(small) {}

  bool addCar(int carType) {
    switch (carType) {
      case 1:
        if (big_ > 0) {
          big_--;
          return true;
        }
        break;
      case 2:
        if (medium_ > 0) {
          medium_--;
          return true;
        }
        break;
      case 3:
        if (small_ > 0) {
          small_--;
          return true;
        }
        break;
    }
    return false;
  }

 private:
  int big_;
  int medium_;
  int small_;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
