/*
 * @lc app=leetcode id=1275 lang=rust
 *
 * [1275] Find Winner on a Tic Tac Toe Game
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
    pub fn tictactoe(moves: Vec<Vec<i32>>) -> String {
        let mut a = [0; 8];
        let mut b = [0; 8];
        for i in 0..moves.len() {
            let r = moves[i][0];
            let c = moves[i][1];
            if i % 2 == 0 {
                a[r as usize] += 1;
                a[(c + 3) as usize] += 1;
                if r == c {
                    a[6] += 1;
                }
                if r == (2 - c) {
                    a[7] += 1;
                }
            } else {
                b[r as usize] += 1;
                b[(c + 3) as usize] += 1;
                if r == c {
                    b[6] += 1;
                }
                if r == (2 - c) {
                    b[7] += 1;
                }
            }
        }
        for i in 0..8 {
            if a[i] == 3 {
                return "A".to_string();
            }
            if b[i] == 3 {
                return "B".to_string();
            }
        }
        if moves.len() == 9 {
            "Draw".to_string()
        } else {
            "Pending".to_string()
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::tictactoe(vec![
            vec![0, 0],
            vec![2, 0],
            vec![1, 1],
            vec![2, 1],
            vec![2, 2]
        ]),
        "A".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::tictactoe(vec![
            vec![0, 0],
            vec![1, 1],
            vec![0, 1],
            vec![0, 2],
            vec![1, 0],
            vec![2, 0]
        ]),
        "B".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::tictactoe(vec![
            vec![0, 0],
            vec![1, 1],
            vec![2, 0],
            vec![1, 0],
            vec![1, 2],
            vec![2, 1],
            vec![0, 1],
            vec![0, 2],
            vec![2, 2]
        ]),
        "Draw".to_string()
    );
}
