class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head)
      return NULL;
    if (!head->next)
      return new TreeNode(head->val);
    // first find middle node, then it will be our root
    ListNode *slow = head;
    ListNode *slow_prev = NULL;
    ListNode *fast = head;

    while (fast && fast->next) {
      slow_prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    // now slow is at the middle
    // now we recursive call on left LL and right LL
    // left LL starts at head, right LL starts at slow->next
    // before that, we need to break the lists, hence taking slow_prev

    TreeNode *root = new TreeNode(slow->val);
    slow_prev->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
  }
};