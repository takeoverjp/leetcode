/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* ret_list = nullptr;
    ListNode* last_node = nullptr;
    ListNode* node = nullptr;
    while (l1 || l2) {
      if (l1 && l2) {
        if (l1->val < l2->val) {
          node = new ListNode(l1->val);
          l1 = l1->next;
        } else {
          node = new ListNode(l2->val);
          l2 = l2->next;
        }
      } else if (l1) {
        node = new ListNode(l1->val);
        l1 = l1->next;
      } else if (l2) {
        node = new ListNode(l2->val);
        l2 = l2->next;
      }
      if (!ret_list || !last_node) {
        ret_list = node;
        last_node = node;
      } else {
        last_node->next = node;
        last_node = node;
      }
    }
    return ret_list;
  }
};
// @lc code=end
