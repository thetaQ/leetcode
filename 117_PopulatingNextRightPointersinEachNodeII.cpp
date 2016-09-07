#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        TreeLinkNode *dummy = new TreeLinkNode(0);
        TreeLinkNode *prev = dummy;
        while(root != NULL)
        {
            if(root->left != NULL)
            {
                prev->next = root->left;
                prev = prev->next;
            }
            if(root->right != NULL)
            {
                prev->next = root->right;
                prev = prev->next;
            }
            root = root->next;
            if(root == NULL)
            {
                prev = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
        delete dummy;
    }
};