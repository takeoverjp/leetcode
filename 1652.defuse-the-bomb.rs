/*
 * @lc app=leetcode id=1652 lang=rust
 *
 * [1652] Defuse the Bomb
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

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
    pub right: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

#[macro_export]
macro_rules! list_node {
    () => {
        None
    };
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
impl Solution {
    pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
        let mut res = vec![0; code.len()];
        if k == 0 {
            return res;
        }
        for (i, item) in res.iter_mut().enumerate() {
            let mut it = 0;
            match k.cmp(&0) {
                std::cmp::Ordering::Greater => {
                    let mut j = i + 1;
                    while it < k {
                        if j == code.len() {
                            j = 0;
                        }
                        *item += code[j];
                        it += 1;
                        j += 1;
                    }
                }
                std::cmp::Ordering::Less => {
                    let mut j = i as i32 - 1;
                    while it > k {
                        if j < 0 {
                            j = code.len() as i32 - 1;
                        }
                        *item += code[j as usize];
                        it -= 1;
                        j -= 1;
                    }
                }
                _ => todo!(),
            }
        }
        res
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::decrypt(vec![5, 7, 1, 4], 3), vec![12, 10, 16, 13]);
}

#[test]
fn test2() {
    assert_eq!(Solution::decrypt(vec![1, 2, 3, 4], 0), vec![0, 0, 0, 0]);
}

#[test]
fn test3() {
    assert_eq!(Solution::decrypt(vec![2, 4, 9, 3], -2), vec![12, 5, 6, 13]);
}
