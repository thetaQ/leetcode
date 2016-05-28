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
    
    void helper(TreeNode *root, vector<vector<int>>& result, int level)
    {
        if(root == nullptr)
            return;
        if(result.size() == level)
        {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        helper(root->left, result, level+1);
        helper(root->right, result, level+1);
        return;
    }
    
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        helper(root, result, 0);
        return result;
    }
};