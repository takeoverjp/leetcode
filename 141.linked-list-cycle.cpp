/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

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
  bool hasCycle(ListNode *head) {
    while(head) {
    for (const auto ptr : nodes) {
      if (ptr == head) return true;
    }
    if (!head->next) return false;
    nodes.push_back(head);
    head = head->next;
    }
    return false;
  }

 private:
  vector<ListNode *> nodes;
};
// @lc code=end
