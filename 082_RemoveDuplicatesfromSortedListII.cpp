#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = head, *slow = dummy;
        while(fast != NULL)
        {
            while(fast->next != NULL && fast->val == fast->next->val)
            {
                fast = fast->next;
            }
            if(slow->next != fast)
            {
                slow->next = fast->next;
                fast = slow->next;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};