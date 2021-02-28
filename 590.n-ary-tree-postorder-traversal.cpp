/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<int> postorder(Node* root) {
    vector<int> ret;
    postorder(root, ret);
    return ret;
  }

  void postorder(Node* root, vector<int>& ret) {
    if (root == nullptr) {
      return;
    }
    for (auto child : root->children) {
      postorder(child, ret);
    }
    ret.push_back(root->val);
  }
};
// @lc code=end
