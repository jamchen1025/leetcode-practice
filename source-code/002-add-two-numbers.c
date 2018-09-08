#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* createListFromArray(int* data, const int len) {
  struct ListNode* root = NULL;
  struct ListNode* prev = NULL;
  for (int i = 0; i < len; i++) {
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    n->val = data[i];
    n->next = NULL;
    if (prev != NULL) {
      prev->next = n;
    }
    if (root == NULL) {
      root = n;
    }
    prev = n;
  }
  return root;
}

void showList(struct ListNode* l) {
  if (l == NULL) {
    return;
  }

  while (l != NULL) {
    printf("%d ", l->val);
    l = l->next;
  }
  printf("\n");
}

void deleteList(struct ListNode** l) {
  if (*l == NULL) {
    return;
  }

  struct ListNode* next = NULL;
  while (*l != NULL) {
    next = (*l)->next;
    free(*l);
    *l = next;
  }

  return;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* result = NULL;
  struct ListNode* prev = NULL;
  int carry = 0;
  while (l1 != NULL || l2 != NULL || carry != 0) {
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    int sum = 0;
    if (l1 != NULL) {
      sum += l1->val;
      l1 = l1->next;
    }

    if (l2 != NULL) {
      sum += l2->val;
      l2 = l2->next;
    }

    if (carry != 0) {
      sum += carry;
    }

    n->val = sum % 10;
    carry = sum / 10;

    if (prev != NULL) {
      prev->next = n;
    }
    prev = n;

    if (result == NULL) {
      result = n;
    }
  }
  prev->next = NULL;
  return result;
}

int main() {
  int a[] = {2, 4, 7, 2};
  int b[] = {5, 6, 4, 7};
  struct ListNode* l1 = createListFromArray(a, sizeof(a) / sizeof(int));
  struct ListNode* l2 = createListFromArray(b, sizeof(b) / sizeof(int));

  struct ListNode* r = addTwoNumbers(l1, l2);
  showList(&r);
  deleteList(&r);
  showList(&r);
  // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  // Output: 7 -> 0 -> 8
  // Explanation: 342 + 465 = 807.

  return 0;
}
