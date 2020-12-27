/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  bool isPalindrome(ListNode* head) {
    int cnt = count(head);
    vector<int> vec;
    ListNode* node = head;
    int last;
    int first;
    if (cnt % 2) {
      last = cnt / 2 - 1;
      first = cnt / 2 + 1;
    } else {
      last = cnt / 2 - 1;
      first = cnt / 2;
    }
    for (int i = 0; i < cnt; i++) {
      if (i <= last) {
        vec.push_back(node->val);
      } else if (i >= first) {
        int num = vec.back();
        vec.pop_back();
        if (num != node->val) {
          return false;
        }
      }
      node = node->next;
    }
    return true;
  }

 private:
  int count(ListNode* head) {
    int count = 0;
    for (ListNode* node = head; node; node = node->next) {
      count++;
    }
    return count;
  }
};
// @lc code=end
