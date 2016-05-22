#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        if(node == NULL)
            return;
        
        ListNode *next = node->next; 
        //next is not the tail, so next != NULL
        node->val = next->val;
        node->next = next->next;
    }
};

int main(void)
{
    Solution solution;
    solution.deleteNode(NULL);
    return 0;
}

