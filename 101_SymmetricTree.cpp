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
    bool helper(TreeNode *left, TreeNode *right)
    {
        if(left == nullptr && right == nullptr)
            return true;
        else if(left == nullptr || right == nullptr)
            return false;
        else if(left->val == right->val)
        {
            return helper(left->left, right->right) && helper(left->right, right->left);
        }
        else
            return false;
    }
    
    bool isSymmetric(TreeNode *root)
    {
        if(root == nullptr)
            return true;
        
        return helper(root->left, root->right);
    }
};