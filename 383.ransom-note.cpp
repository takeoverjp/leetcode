/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int len = ransomNote.length();
        for (int i = 0; i < len; i++) {
            int pos = magazine.find(ransomNote[i]);
            if (pos == string::npos) {
                return false;
            }
            magazine[pos] = 'X';
        }
        return true;
    }
};
// @lc code=end

int
main () {
  Solution s;
  assert(s.canConstruct("a", "b") == false);
  assert(s.canConstruct("aa", "ab") == false);
  assert(s.canConstruct("aa", "aab") == true);
  return 0;
}
