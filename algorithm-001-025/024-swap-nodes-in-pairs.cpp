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
  ListNode* swapPairs(ListNode* head) {
    if (head == NULL) {
      return nullptr;
    }

    ListNode* pre_node = NULL;
    for (ListNode* current = head; current != NULL && current->next != NULL;
         current = current->next) {
      ListNode* temp = current->next;
      current->next = current->next->next;
      temp->next = current;

      if (pre_node != NULL) {
        pre_node->next = temp;
      }
      pre_node = current;

      // 當第一次交換時，修正 head 位置
      if (head == current) {
        head = temp;
      }
    }

    return head;
  }
};

int main() {
  int input_data_1[] = {1, 2, 3, 4};
  ListNode* list_1 =
      CreateListFromArray(input_data_1, sizeof(input_data_1) / sizeof(int));

  Solution s;
  ListNode* r = s.swapPairs(list_1);

  DisplayList(r);
  // Output: 2->1->4->3
  DestroyList(r);

  return 0;
}
