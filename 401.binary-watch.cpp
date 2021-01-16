/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for (int h = 0; h < 12; h++) {
            int bith = countBit(h);
            for (int m = 0; m < 60; m++) {
                int bitm = countBit(m);
                if (bith + bitm == num) {
                    stringstream ss;
                    ss << h << ":" << setw(2) << setfill('0') << m;
                    ret.push_back(ss.str());
                }
            }
        }
        return ret;
    }
    private:
    int countBit(int num) {
        int ret = 0;
        while (num) {
            ret += num % 2;
            num /= 2;
        }
        return ret;
    }
};
// @lc code=end

