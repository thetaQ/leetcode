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
    void sumNumbersCore(TreeNode *root, int cur_path, int& sum)
    {
        int new_cur = cur_path * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += new_cur;
            return;
        }
        if(root->left != NULL)
            sumNumbersCore(root->left, new_cur, sum);
        if(root->right != NULL)
            sumNumbersCore(root->right, new_cur, sum);
    }

    int sumNumbers(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int cur_path = 0;
        int sum = 0;
        sumNumbersCore(root, 0, sum);
        return sum;
    }
};