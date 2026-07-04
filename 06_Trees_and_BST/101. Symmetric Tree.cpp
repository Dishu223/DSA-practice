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
  bool isSymmetrical(TreeNode *left, TreeNode *right) {
    if (!left && !right)
      return true;
    if (!left || !right)
      return false;
    if (left->val == right->val && isSymmetrical(left->left, right->right) &&
        isSymmetrical(left->right, right->left))
      return true;
    return false;
  }
  bool isSymmetric(TreeNode *root) {
    return isSymmetrical(root->left, root->right);
  }
};