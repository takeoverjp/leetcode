/*
 * @lc app=leetcode id=1678 lang=rust
 *
 * [1678] Goal Parser Interpretation
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
    pub fn interpret(command: String) -> String {
        let command = command.chars().collect::<Vec<char>>();
        Solution::interpret_r(command, 0)
    }

    fn interpret_r(command: Vec<char>, index: usize) -> String {
        if index >= command.len() {
            return "".to_string();
        }
        if command[index] == 'G' {
            return "G".to_owned() + &Solution::interpret_r(command, index + 1);
        } else if command[index] == '(' && command[index + 1] == ')' {
            return "o".to_owned() + &Solution::interpret_r(command, index + 2);
        }
        "al".to_owned() + &Solution::interpret_r(command, index + 4)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::interpret("G()(al)".to_string()),
        "Goal".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::interpret("G()()()()(al)".to_string()),
        "Gooooal".to_string()
    );
}
#[test]
fn test3() {
    assert_eq!(
        Solution::interpret("(al)G(al)()()G".to_string()),
        "alGalooG".to_string()
    );
}
