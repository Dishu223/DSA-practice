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
  vector<double> averageOfLevels(TreeNode *root) {
    if (!root)
      return {};

    queue<TreeNode *> que;
    vector<double> result;

    que.push(root);

    while (!que.empty()) {
      int level_size = que.size();
      int og_size = level_size;
      vector<int> current_level;

      long long sum = 0;

      while (level_size--) {
        TreeNode *node = que.front();
        que.pop();
        sum += node->val;

        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }

      result.push_back((double)sum / og_size);
    }
    return result;
  }
};