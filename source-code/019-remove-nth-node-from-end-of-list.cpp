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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL || head->next == NULL) {
      return NULL;
    }
    ListNode* fast = head;
    ListNode* current = head;

    for (int i = 0; i < n; i++, fast = fast->next)
      ;

    // delete head
    if (fast == NULL) {
      return head->next;
    }

    // move current to index: n - 1
    while (fast != NULL && fast->next != NULL) {
      fast = fast->next;
      current = current->next;
    }
    ListNode* d = current->next;
    current->next = d->next;
    d->next = NULL;
    delete d;
    return head;
  }
};

int main() {
  int input_data_1[] = {1, 2, 3, 4, 5};
  ListNode* list_1 =
      CreateListFromArray(input_data_1, sizeof(input_data_1) / sizeof(int));

  Solution s;
  ListNode* r = s.removeNthFromEnd(list_1, 2);

  DisplayList(r);
  // Output: After removing the second node from the end, the linked list
  // becomes 1->2->3->5.

  DestroyList(r);

  return 0;
}
