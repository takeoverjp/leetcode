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

#include <assert.h>

#include <stack>
#include <string>

using namespace std;

// @lc code=start

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret_list = new ListNode();
        ListNode* node = ret_list;
        if (l1 && l2) {
            if (l1->val < l2->val) {
                node->next = new ListNode(l1->val);
                node = node->next;
          } else {
                node->next = new ListNode(l2->val);
                node = node->next;
            }
        } else if (l1) {
                node->next = new ListNode(l1->val);
                node = node->next;
        } else if (l2) {
                node->next = new ListNode(l2->val);
                node = node->next;
        } else {
            return ret_list;
        }
    }
};
// @lc code=end


int main() {
  Solution s;
  s.mergeTwoLists();
}
