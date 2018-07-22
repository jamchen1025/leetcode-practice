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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* p = NULL;
    ListNode* p1 = NULL;
    ListNode* p2 = NULL;
    while (lists.size() > 1) {
      p1 = lists.back();
      lists.pop_back();
      p2 = lists.back();
      lists.pop_back();
      p = mergeTwoLists(p1, p2);

      lists.insert(lists.begin(), p);
    }
    return lists.size() == 1 ? lists[0] : NULL;
  }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    // 使用 **child 可以直接修改 LinkNode 中的 next node 指向的 位址
    ListNode** child = &head;

    ListNode* n = NULL;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        n = l1;
        l1 = l1->next;
      } else {
        n = l2;
        l2 = l2->next;
      }
      *child = n;
      child = &n->next;
    }

    ListNode* rest = (l1 != NULL) ? l1 : l2;
    *child = rest;

    return head;
  }
};

int main() {
  int input_data_1[] = {1, 4, 5};
  ListNode* list_1 =
      CreateListFromArray(input_data_1, sizeof(input_data_1) / sizeof(int));
  int input_data_2[] = {1, 3, 4};
  ListNode* list_2 =
      CreateListFromArray(input_data_2, sizeof(input_data_2) / sizeof(int));
  int input_data_3[] = {2, 6};
  ListNode* list_3 =
      CreateListFromArray(input_data_3, sizeof(input_data_3) / sizeof(int));

  vector<ListNode*> lists{list_1, list_2, list_3};

  Solution s;
  ListNode* r = s.mergeKLists(lists);

  DisplayList(r);
  // Output: 1->1->2->3->4->4->5->6
  DestroyList(r);

  return 0;
}
