/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    struct seq_t {
      char c;
      u_short count;
    };
    int nlen = name.length();
    int tlen = typed.length();
    if (nlen > tlen) {
      return false;
    }

    int nidx = 0;
    seq_t* nseq = static_cast<seq_t*>(alloca(sizeof(seq_t) * nlen));
    memset(nseq, 0, sizeof(seq_t) * nlen);
    nseq[0].c = name[0];
    nseq[0].count = 1;
    for (int i = 1; i < nlen; i++) {
      if (nseq[nidx].c == name[i]) {
        nseq[nidx].count++;
      } else {
        nseq[++nidx].c = name[i];
        nseq[nidx].count = 1;
      }
    }

    int tidx = 0;
    seq_t* tseq = static_cast<seq_t*>(alloca(sizeof(seq_t) * tlen));
    memset(tseq, 0, sizeof(seq_t) * tlen);
    tseq[0].c = typed[0];
    tseq[0].count = 1;
    for (int i = 1; i < tlen; i++) {
      if (tseq[tidx].c == typed[i]) {
        tseq[tidx].count++;
      } else {
        tseq[++tidx].c = typed[i];
        tseq[tidx].count = 1;
      }
    }

    if (nidx != tidx) {
      return false;
    }

    for (int i = 0; i <= nidx; i++) {
      //   cout << nseq[i].c << "," << nseq[i].count << "," << tseq[i].c << ","
      //        << tseq[i].count << endl;
      if (nseq[i].c != tseq[i].c || nseq[i].count > tseq[i].count) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.isLongPressedName("alex", "aal"), false);
  ASSERT_EQ(s.isLongPressedName("alex", "aaleex"), true);
  ASSERT_EQ(s.isLongPressedName("saeed", "ssaaedd"), false);
  ASSERT_EQ(s.isLongPressedName("leelee", "lleeelee"), true);
  ASSERT_EQ(s.isLongPressedName("laiden", "laiden"), true);
  return 0;
}
