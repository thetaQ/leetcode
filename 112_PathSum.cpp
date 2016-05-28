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
    
    bool helper(TreeNode *root, int cur_sum, int sum)
    {
        if(root == NULL)
            return false;
        else if(root->left == NULL && root->right == NULL)
            return cur_sum + root->val == sum;
        else
            return helper(root->left, cur_sum + root->val, sum)
                || helper(root->right, cur_sum + root->val, sum);
    }
    
    bool hasPathSum(TreeNode *root, int sum)
    {
        return helper(root, 0, sum);
    }
};