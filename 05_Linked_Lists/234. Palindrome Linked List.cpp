/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *next_node = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next_node;
    }
    return prev;
  }

  bool isPalindrome(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *second_half_head = reverseList(slow);
    ListNode *first_half_head = head;

    while (second_half_head != nullptr) {
      if (first_half_head->val != second_half_head->val)
        return false;
      first_half_head = first_half_head->next;
      second_half_head = second_half_head->next;
    }
    return true;
  }
};