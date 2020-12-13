/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

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
  ListNode* removeElements(ListNode* head, int val) {
    while (head) {
      if (head->val != val) {
        break;
      }
      head = head->next;
    }
    ListNode* node = head;
    while (node) {
      ListNode* next = node->next;
      while (next) {
        if (next->val == val) {
          node->next = next->next;
          next = node->next;
        } else {
          break;
        }
      }
      node = node->next;
    }
    return head;
  }
};
// @lc code=end
