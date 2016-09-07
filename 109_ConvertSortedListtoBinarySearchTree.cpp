#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    ListNode *get_middle(ListNode *head)
    {
        if(head == NULL)
            return NULL;
        ListNode *fast = head, *slow = head;
        ListNode *prev = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev != NULL)
            prev->next = NULL;
        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        
        ListNode *middle = get_middle(head);
        if(middle == NULL)
            return NULL;
        TreeNode *root = new TreeNode(middle->val);
        if(middle == head)
        {
            root->left = NULL;
        }
        else
        {
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(middle->next);
        return root;
    }
};