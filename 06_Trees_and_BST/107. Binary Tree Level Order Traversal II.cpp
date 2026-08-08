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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (!root)
      return {};

    queue<TreeNode *> que;
    vector<vector<int>> result;

    que.push(root);

    while (!que.empty()) {
      vector<int> current_level;
      int level_size = que.size();

      while (level_size--) {
        TreeNode *node = que.front();
        que.pop();

        current_level.push_back(node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      result.push_back(current_level);
    }

    reverse(result.begin(), result.end());
    return result;
  }
};