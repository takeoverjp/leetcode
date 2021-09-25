/*
 * @lc app=leetcode id=21 lang=rust
 *
 * [21] Merge Two Sorted Lists
 */

struct Solution;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_two_lists(
        mut l1: Option<Box<ListNode>>,
        mut l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = None;
        let mut p_next = &mut dummy;

        while l1.is_some() && l2.is_some() {
            let lone = &mut l1;
            let ltwo = &mut l2;

            let l = if lone.as_ref().unwrap().val < ltwo.as_ref().unwrap().val {
                lone
            } else {
                ltwo
            };

            std::mem::swap(l, p_next);
            std::mem::swap(l, &mut p_next.as_mut().unwrap().next);
            p_next = &mut p_next.as_mut().unwrap().next;
        }

        std::mem::swap(p_next, if l1.is_none() { &mut l2 } else { &mut l1 });
        dummy
    }
}
// @lc code=end

#[test]
fn test1() {
    let l1 = Some(Box::new(ListNode {
        val: 1,
        next: Some(Box::new(ListNode {
            val: 2,
            next: Some(Box::new(ListNode { val: 4, next: None })),
        })),
    }));
    let l2 = Some(Box::new(ListNode {
        val: 1,
        next: Some(Box::new(ListNode {
            val: 3,
            next: Some(Box::new(ListNode { val: 4, next: None })),
        })),
    }));
    let exp = Some(Box::new(ListNode {
        val: 1,
        next: Some(Box::new(ListNode {
            val: 1,
            next: Some(Box::new(ListNode {
                val: 2,
                next: Some(Box::new(ListNode {
                    val: 3,
                    next: Some(Box::new(ListNode {
                        val: 4,
                        next: Some(Box::new(ListNode { val: 4, next: None })),
                    })),
                })),
            })),
        })),
    }));
    assert_eq!(Solution::merge_two_lists(l1, l2), exp);
}

#[test]
fn test2() {
    assert_eq!(Solution::merge_two_lists(None, None), None);
}

#[test]
fn test3() {
    let l2 = Some(Box::new(ListNode { val: 0, next: None }));
    let exp = Some(Box::new(ListNode { val: 0, next: None }));
    assert_eq!(Solution::merge_two_lists(None, l2), exp);
}
