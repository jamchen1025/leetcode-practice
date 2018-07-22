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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) {
      return nullptr;
    }

    if (k <= 0 || head->next == NULL) {
      return head;
    }

    ListNode fake(0);
    fake.next = head;
    ListNode* p = &fake;

    while (p) {
      p->next = reverseList(p->next, k);
      for (int i = 0; p && i < k; i++) {
        p = p->next;
      }
    }

    return fake.next;
  }

  ListNode* reverseList(ListNode* head, int k) {
    // 找出最後一的 ListNode ，並確認連起來的 node 數是否夠 revere
    ListNode* end = head;
    int count = 0;
    while (end != NULL && count < k) {
      end = end->next;
      ++count;
    }
    if (count < k) {
      return head;
    }

    ListNode* prev = head;
    ListNode* current = head->next;
    prev->next = end;
    count = 0;
    while (current != NULL && count < k - 1) {
      ListNode* temp = current;
      current = current->next;
      temp->next = prev;

      prev = temp;
      ++count;
    }
    return prev;
  };
};

int main() {
  int input_data_1[] = {1, 2, 3, 4, 5};
  ListNode* list_1 =
      CreateListFromArray(input_data_1, sizeof(input_data_1) / sizeof(int));

  Solution s;
  ListNode* r = s.reverseKGroup(list_1, 2);

  DisplayList(r);
  // Output:
  // For k = 2, you should return: 2->1->4->3->5
  // For k = 3, you should return: 3->2->1->4->5
  DestroyList(r);

  return 0;
}
