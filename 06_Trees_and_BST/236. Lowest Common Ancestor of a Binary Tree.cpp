/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q)
      return root;
    TreeNode *left_sub = lowestCommonAncestor(root->left, p, q);
    TreeNode *right_sub = lowestCommonAncestor(root->right, p, q);

    if (left_sub && right_sub)
      return root;
    return left_sub ? left_sub : right_sub;
  }
};