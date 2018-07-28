#include <iostream>
#include <vector>
#include <string>

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    ListNode** child = &head;

    ListNode* n = NULL;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        n = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        n = new ListNode(l2->val);
        l2 = l2->next;
      }
      *child = n;
      child = &n->next;
    }

    ListNode* rest = (l1 != NULL) ? l1 : l2;
    while (rest != NULL) {
      n = new ListNode(rest->val);
      rest = rest->next;
      *child = n;
      child = &n->next;
    }

    return head;
  }
};

int main() {
  int input_data_1[] = {1, 2, 4};
  ListNode* list_1 =
      CreateListFromArray(input_data_1, sizeof(input_data_1) / sizeof(int));
  int input_data_2[] = {1, 3, 4};
  ListNode* list_2 =
      CreateListFromArray(input_data_2, sizeof(input_data_2) / sizeof(int));

  Solution s;
  ListNode* r = s.mergeTwoLists(list_1, list_2);

  DisplayList(r);
  // Output: 1->1->2->3->4->4
  DestroyList(r);
  DestroyList(list_1);
  DestroyList(list_2);

  return 0;
}
