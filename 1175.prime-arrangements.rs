/*
 * @lc app=leetcode id=1175 lang=rust
 *
 * [1175] Prime Arrangements
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
    pub fn num_prime_arrangements(n: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        const PRIME: [i32; 25] = [
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
            89, 97,
        ];
        let factorial_mod = |n: i32| -> i64 { (2..=n as i64).fold(1, |acc, x| (acc * x) % MOD) };
        let num_primes = PRIME.iter().take_while(|&&x| x <= n).count() as i32;
        ((factorial_mod(num_primes) * factorial_mod(n - num_primes)) % MOD) as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::num_prime_arrangements(5), 12);
}

#[test]
fn test2() {
    assert_eq!(Solution::num_prime_arrangements(100), 682289015);
}
