/*
 * @lc app=leetcode id=155 lang=rust
 *
 * [155] Min Stack
 */

// @lc code=start
struct MinStack {
    stack: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    fn new() -> Self {
        MinStack{stack: vec![]}
    }
    
    fn push(&mut self, val: i32) {
        self.stack.push(val)
    }
    
    fn pop(&mut self) {
        self.stack.pop();        
    }
    
    fn top(&self) -> i32 {
        self.stack[self.stack.len() - 1]        
    }
    
    fn get_min(&self) -> i32 {
        let mut min_val = std::i32::MAX;
        for num in &self.stack {
            min_val = std::cmp::min(min_val, *num);
        }
        min_val
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */
// @lc code=end

