/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    ListNode* node = head;
    while (node) {
      len++;
      node = node->next;
    }

    node = head;

    int index = len - n;
    if (len == 1) {
      return nullptr;
    }
    if (index == 0) {
      return head->next;
    }
    while (index--) {
      if (index == 0) {
        node->next = node->next->next;
        break;
      }
      node = node->next;
    }
    return head;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.removeNthFromEnd(), );
  return 0;
}
