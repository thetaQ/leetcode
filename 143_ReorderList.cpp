#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head)
    {
        // write your code here
        if(head == NULL || head->next == NULL)
            return;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //slow is mid, reverse right half
        ListNode *curr = slow->next;
        slow->next = NULL;
        
        ListNode *prev = NULL;
        while(curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        //new head is prev, merge the two list
        ListNode *p1 = head, *p2 = prev;
        while(p1 != NULL)
        {
            ListNode *tmp = p1->next;
            p1->next = p2;
            p1 = p1->next;
            p2 = tmp;
        }
    }
};