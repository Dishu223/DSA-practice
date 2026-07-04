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
  TreeNode *solve(vector<int> &nums, int start, int end) {
    if (start > end)
      return NULL;

    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = solve(nums, start, mid - 1);
    root->right = solve(nums, mid + 1, end);
    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return (solve(nums, 0, nums.size() - 1));
  }
};

// We are given sorted array,
// which is the same as INORDER TRAVERSAL OF A BST!
// So, we can construct a BST from sorted array by picking the middle element as
// the root and recursively constructing the left and right subtrees.
// In this way, the tree will be height balanced.
// Time complexity: O(N)
// Space complexity: O(log N) for recursion stack