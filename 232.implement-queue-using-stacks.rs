/*
 * @lc app=leetcode id=232 lang=rust
 *
 * [232] Implement Queue using Stacks
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
struct MyQueue {
    vec: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {
    fn new() -> Self {
        MyQueue { vec: vec![] }
    }

    fn push(&mut self, x: i32) {
        self.vec.push(x)
    }

    fn pop(&mut self) -> i32 {
        let ret = self.peek();
        self.vec.remove(0);
        ret
    }

    fn peek(&self) -> i32 {
        *self.vec.get(0).unwrap()
    }

    fn empty(&self) -> bool {
        self.vec.len() == 0
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */
// @lc code=end

#[test]
fn test1() {
    let mut q = MyQueue::new();
    q.push(1);
    q.push(2);
    assert!(!q.empty());
    assert_eq!(q.peek(), 1);
    assert_eq!(q.pop(), 1);
    assert!(!q.empty());
    assert_eq!(q.peek(), 2);
    assert_eq!(q.pop(), 2);
    assert!(q.empty());
}
