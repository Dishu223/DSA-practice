class Solution {
public:
  Node *copyRandomList(Node *head) {

    if (!head)
      return head;

    unordered_map<Node *, Node *> mp;

    Node *newHead = NULL;
    Node *prev = NULL;

    Node *curr = head;

    while (curr) {
      Node *temp = new Node(curr->val);
      mp[curr] = temp;
      if (!newHead) {
        newHead = temp;
        prev = newHead;
      } else {
        prev->next = temp;
        prev = temp;
      }
      curr = curr->next;
    }

    curr = head;
    Node *newCurr = newHead;

    while (curr) {
      if (!curr->random)
        newCurr->random = NULL;
      else
        newCurr->random = mp[curr->random];
      curr = curr->next;
      newCurr = newCurr->next;
    }
    return newHead;
  }
};