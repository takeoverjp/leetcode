#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if l1 is None and l2 is None:
            return None

        node1 = l1
        node2 = l2

        ret = None

        carry = 0
        while node1 is not None or node2 is not None or carry != 0:
            sum = 0
            if node1 is not None:
                sum += node1.val
            if node2 is not None:
                sum += node2.val
            sum += carry
        
            carry = 0
            if sum >= 10:
                carry = sum // 10
            tmp = ListNode(sum % 10)
            if ret is None:
                ret = tmp
            else:
                rnode.next = tmp
            rnode = tmp

            if node1 is not None:
                node1 = node1.next
            if node2 is not None:
                node2 = node2.next

        return ret

        
# @lc code=end

