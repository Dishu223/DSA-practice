/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<int> largestValues(TreeNode *root) {
    if (!root)
      return {};

    queue<TreeNode *> que;
    vector<int> result;

    que.push(root);

    while (!que.empty()) {
      int level_size = que.size();
      long long max_this_level = INT_MIN;
      while (level_size--) {
        TreeNode *node = que.front();
        que.pop();
        max_this_level = max(max_this_level, (long long)node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      result.push_back(max_this_level);
    }
    return result;
  }
};