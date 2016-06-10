#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode * removeNthFromEnd(ListNode *head, int n)
    {
        if(n == 0)
            return head;
        
        ListNode *fast = head, *slow = head;
        while(n--)
        {
            fast = fast->next;  //always valid
        }
        if(fast == NULL)
            return slow->next;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};