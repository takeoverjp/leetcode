/*
 * @lc app=leetcode id=1408 lang=rust
 *
 * [1408] String Matching in an Array
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
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let mut ans = vec![];
        for i in &words {
            for j in &words {
                if *i == *j {
                    continue;
                }
                if j.contains(i) {
                    ans.push(i.clone());
                    break;
                }
            }
        }
        ans
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::string_matching(vec![
            "mass".to_string(),
            "as".to_string(),
            "hero".to_string(),
            "superhero".to_string()
        ]),
        vec!["as".to_string(), "hero".to_string()]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::string_matching(vec![
            "leetcode".to_string(),
            "et".to_string(),
            "code".to_string()
        ]),
        vec!["et".to_string(), "code".to_string()]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::string_matching(vec![
            "blue".to_string(),
            "green".to_string(),
            "bu".to_string()
        ]),
        Vec::<String>::new()
    );
}
