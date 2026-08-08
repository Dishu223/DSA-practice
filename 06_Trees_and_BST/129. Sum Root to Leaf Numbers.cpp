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
  int dfs(TreeNode *node, int current_sum) {
    if (!node)
      return 0;
    current_sum = current_sum * 10 + node->val;

    if (!node->left && !node->right)
      return current_sum;
    return dfs(node->left, current_sum) + dfs(node->right, current_sum);
  }

  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
};