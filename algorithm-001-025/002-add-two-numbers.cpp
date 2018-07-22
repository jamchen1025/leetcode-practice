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
    ListNode* root = NULL;
    ListNode** child = &root;
    ListNode* n = NULL;
    int carry = 0, sum = 0;
    while (l1 != NULL && l2 != NULL) {
      sum = l1->val + l2->val + carry;
      n = new ListNode(sum % 10);
      carry = sum / 10;
      *child = n;
      child = &(n->next);

      l1 = l1->next;
      l2 = l2->next;
    }

    ListNode* left = (l1 == NULL) ? l2 : l1;
    while (left != NULL) {
      sum = left->val + carry;
      n = new ListNode(sum % 10);
      carry = sum / 10;
      *child = n;
      child = &(n->next);

      left = left->next;
    }

    if (carry != 0) {
      n = new ListNode(carry);
      *child = n;
    }

    return root;
  };
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
