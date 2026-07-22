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
  void reorderList(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    } // get to middle

    ListNode *prev = nullptr;
    ListNode *curr = slow->next;
    while (curr) {
      ListNode *next_node = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next_node;
    } // reverse the 2nd half

    slow->next = nullptr; // split the 2 lists

    ListNode *first_head = head;
    ListNode *second_head = prev;

    while (first_head && second_head) {
      ListNode *temp1 = first_head->next;
      ListNode *temp2 = second_head->next;
      first_head->next = second_head;
      second_head->next = temp1;

      first_head = temp1;
      second_head = temp2;
    }
  }
};