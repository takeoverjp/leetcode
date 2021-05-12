/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::stack<ListNode *> stackA, stackB;
    while (headA) {
      stackA.push(headA);
      headA = headA->next;
    }
    while (headB) {
      stackB.push(headB);
      headB = headB->next;
    }
    ListNode *ret = nullptr;
    while (!stackA.empty() && !stackB.empty()) {
      ListNode *lastA = stackA.top();
      ListNode *lastB = stackB.top();
      if (lastA != lastB) {
        break;
      }
      ret = lastA;
      stackA.pop();
      stackB.pop();
    }
    return ret;
  }
};
// @lc code=end
