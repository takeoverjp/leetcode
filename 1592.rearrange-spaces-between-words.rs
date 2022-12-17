/*
 * @lc app=leetcode id=1592 lang=rust
 *
 * [1592] Rearrange Spaces Between Words
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
    pub fn reorder_spaces(text: String) -> String {
        let words = text.split_whitespace();
        let word_num = words.clone().count();
        let space_num = text
            .chars()
            .fold(0, |sum, elem| if elem == ' ' { sum + 1 } else { sum });
        if word_num == 1 && space_num == 0 {
            return text;
        }
        let inter = if word_num == 1 {
            0
        } else {
            space_num / (word_num - 1)
        };
        let last = if word_num == 1 {
            space_num
        } else {
            space_num % (word_num - 1)
        };
        let mut inter_space = String::new();
        let mut last_space = String::new();
        for _i in 0..inter {
            inter_space += " ";
        }
        for _i in 0..last {
            last_space += " ";
        }
        words.fold("".to_string(), |x, elem| {
            if x.is_empty() {
                elem.to_string()
            } else {
                x + &inter_space + elem
            }
        }) + &last_space
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reorder_spaces("  this   is  a sentence ".to_string()),
        "this   is   a   sentence".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::reorder_spaces(" practice   makes   perfect".to_string()),
        "practice   makes   perfect ".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::reorder_spaces("a".to_string()), "a".to_string());
}

#[test]
fn test4() {
    assert_eq!(
        Solution::reorder_spaces("  hello".to_string()),
        "hello  ".to_string()
    );
}
