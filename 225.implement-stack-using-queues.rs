/*
 * @lc app=leetcode id=225 lang=rust
 *
 * [225] Implement Stack using Queues
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
struct MyStack {
    fqueue: std::vec::Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {
    fn new() -> Self {
        MyStack { fqueue: vec![] }
    }

    fn push(&mut self, x: i32) {
        self.fqueue.push(x)
    }

    fn pop(&mut self) -> i32 {
        self.fqueue.pop().unwrap()
    }

    fn top(&self) -> i32 {
        self.fqueue[self.fqueue.len() - 1]
    }

    fn empty(&self) -> bool {
        self.fqueue.len() == 0
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */
// @lc code=end

#[test]
fn test1() {
    let mut obj = MyStack::new();
    obj.push(1);
    obj.push(2);
    assert_eq!(obj.top(), 2);
    assert_eq!(obj.pop(), 2);
    assert!(!obj.empty());
}
