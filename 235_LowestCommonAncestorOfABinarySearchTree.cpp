#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode * lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == NULL)
            return NULL;
        if(p == NULL || q == NULL)
            return NULL;

        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};


int main()
{
    Solution solution;
    TreeNode *node = solution.lowestCommonAncestor(NULL, NULL, NULL);
    cout << node->val << endl;
    return 0;

}
