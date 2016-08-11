#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    int max_to_root(TreeNode *root, int& result)
    {
        if(root == NULL)
            return 0;
        int left = max(0, max_to_root(root->left, result));
        int right = max(0, max_to_root(root->right, result));
        result = max(result, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root)
    {
        int result = INT_MIN;
        max_to_root(root, result);
        return result;
    }
};