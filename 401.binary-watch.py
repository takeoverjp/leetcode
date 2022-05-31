#
# @lc app=leetcode id=401 lang=python3
#
# [401] Binary Watch
#

# @lc code=start
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        # def readBinaryWatch(self, turnedOn: int):
        ret = []
        for h in range(12):
            for m in range(60):
                if (bin(h) + bin(m)).count('1') == turnedOn:
                    ret.append(f"{h}:{m:02}")
        return ret

# @lc code=end


s = Solution()
assert(s.readBinaryWatch(1) == [
       "0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"])
assert(s.readBinaryWatch(9) == [])
