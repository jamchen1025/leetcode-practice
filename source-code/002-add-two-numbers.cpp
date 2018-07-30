/********************************************************************************** 
題目：
https://leetcode.com/problems/add-two-numbers/description/
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
**********************************************************************************
想法：
利用carry記錄sum的進位
利用ListNode** n來修改ListNode的值同時移動到下一點
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CreateListFromArray(int* ptr, const int len) {
  ListNode* node_ptr = NULL;
  ListNode* root_node_ptr = NULL;
  ListNode* parent_node_ptr = NULL;
  for (int i = 0; i < len; i++) {
    if (node_ptr == NULL) {
      node_ptr = new ListNode(*(ptr + i));
      if (root_node_ptr == NULL) root_node_ptr = node_ptr;
      if (parent_node_ptr != NULL) parent_node_ptr->next = node_ptr;
    }
    parent_node_ptr = node_ptr;
    node_ptr = node_ptr->next;
  }
  return root_node_ptr;
}

void DestroyList(ListNode* ptr) {
  if (ptr != NULL) {
    ListNode* next = ptr->next;
    delete ptr;
    DestroyList(next);
  }
}

void DisplayList(ListNode* ptr) {
  while (ptr != NULL) {
    std::cout << ptr->val << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    int sum = 0;
    ListNode* root;
    ListNode** n = &root;
    while (l1 != NULL && l2 != NULL) {
      sum = l1->val + l2->val + carry;
      carry = sum / 10;
      *n = new ListNode(sum % 10);
      n = &(*n)->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    ListNode* rest = (l1 != NULL) ? l1 : l2;
    while (rest != NULL) {
      sum = rest->val + carry;
      carry = sum / 10;
      *n = new ListNode(sum % 10);
      n = &(*n)->next;
      rest = rest->next;
    }

    if (carry != 0) {
      *n = new ListNode(carry);
    }
    return root;
  }
};

int main() {
  int input_data_1[] = {2, 4, 3, 1};
  ListNode* list_1 =
      CreateListFromArray(input_data_1, sizeof(input_data_1) / sizeof(int));
  int input_data_2[] = {5, 6, 4};
  ListNode* list_2 =
      CreateListFromArray(input_data_2, sizeof(input_data_2) / sizeof(int));

  Solution s;
  ListNode* r = s.addTwoNumbers(list_1, list_2);

  DisplayList(r);
  DestroyList(r);
  DestroyList(list_1);
  DestroyList(list_2);
  return 0;
}
