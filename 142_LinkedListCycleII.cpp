#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
            return NULL;
        ListNode *fast = head, *slow = head;
        bool has_cycle = false;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                has_cycle = true;
                break;
            }
        }
        if(!has_cycle)
            return NULL;
        fast = head;
        while(fast != NULL && fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};