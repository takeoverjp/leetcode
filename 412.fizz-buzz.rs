/*
 * @lc app=leetcode id=412 lang=rust
 *
 * [412] Fizz Buzz
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
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut ret = Vec::<String>::new();
        for i in 1..=n {
            if i % 15 == 0 {
                ret.push("FizzBuzz".to_string());
            } else if i % 3 == 0 {
                ret.push("Fizz".to_string());
            } else if i % 5 == 0 {
                ret.push("Buzz".to_string());
            } else {
                ret.push(format!("{}", i))
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::fizz_buzz(3),
        vec!["1".to_string(), "2".to_string(), "Fizz".to_string()]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::fizz_buzz(5),
        vec![
            "1".to_string(),
            "2".to_string(),
            "Fizz".to_string(),
            "4".to_string(),
            "Buzz".to_string()
        ]
    );
}
