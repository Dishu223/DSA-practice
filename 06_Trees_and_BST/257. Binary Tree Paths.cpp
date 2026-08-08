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
  void dfs(TreeNode *node, string current_string, vector<string> &result) {
    if (!node)
      return;

    current_string += to_string(node->val);

    if (!node->left && !node->right) {
      result.push_back(current_string);
      return;
    }
    current_string += "->";
    dfs(node->left, current_string, result);
    dfs(node->right, current_string, result);
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> result;
    if (root)
      dfs(root, "", result);
    return result;
  }
};