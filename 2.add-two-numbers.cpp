/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next){};
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ret = nullptr;
    ListNode* last = nullptr;
    int carry = 0;
    while (1) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      if (last == nullptr) {
        last = new ListNode(sum % 10);
        ret = last;
        if (!(sum || l1 || l2)) {
          break;
        }
      } else {
        if (!(sum || l1 || l2)) {
          break;
        }
        last->next = new ListNode(sum % 10);
        last = last->next;
      }

      carry = sum / 10;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(0);
  return 0;
}
