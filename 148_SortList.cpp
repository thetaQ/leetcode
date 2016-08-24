#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    
    ListNode *get_mid(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        if(left->val < right->val)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            return right;
        }
    }
    
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *mid = get_mid(head);
        ListNode *next = mid->next;
        mid->next = NULL;
        return merge(sortList(head), sortList(next));
    }
};


