/*
 * @lc app=leetcode id=83 lang=rust
 *
 * [83] Remove Duplicates from Sorted List
 */

struct Solution;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

#[macro_export]
macro_rules! list_node {
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let mut node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
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
    pub fn delete_duplicates(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut last = &mut head;
        while last.is_some() {
            let last_val = last.as_ref().unwrap().val;
            // println!("@@@ {}, {:?}", last_val, last);
            while last.as_ref().unwrap().next.is_some()
                && last.as_ref().unwrap().next.as_ref().unwrap().val == last_val
            {
                // println!("@@@@@ {}, {:?}", last_val, last);
                last.as_mut().unwrap().next =
                    last.as_mut().unwrap().next.as_mut().unwrap().next.clone();
            }
            last = &mut last.as_mut().unwrap().next;
        }
        head
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        list_node![1, 2],
        Solution::delete_duplicates(list_node![1, 1, 2])
    );
}

#[test]
fn test2() {
    assert_eq!(
        list_node![1, 2, 3],
        Solution::delete_duplicates(list_node![1, 1, 2, 3, 3])
    );
}

#[test]
fn test3() {
    assert_eq!(
        list_node![1,],
        Solution::delete_duplicates(list_node![1, 1, 1])
    );
}
