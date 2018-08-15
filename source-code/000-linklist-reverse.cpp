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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (curr->next != NULL) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        curr->next = pre;
        return curr;
    }
};

int main() {
    int input_data_1[] = {1, 2, 3, 4, 5};
    ListNode* list_1 =
    CreateListFromArray(input_data_1, sizeof(input_data_1) / sizeof(int));
    
    Solution s;
    ListNode* r = s.reverse(list_1);
    
    DisplayList(r);
    
    DestroyList(r);
    
    return 0;
}
