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
    
    void pathSumCore(vector<vector<int>>& result, TreeNode *root, int sum, vector<int>& path, int cur_sum)
    {
        if(root == NULL)
            return;
        cur_sum += root->val;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(cur_sum == sum)
                result.push_back(path);
        }
        pathSumCore(result, root->left, sum, path, cur_sum);
        pathSumCore(result, root->right, sum, path, cur_sum);
        path.pop_back();
        cur_sum -= root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> result;
        vector<int> path;
        pathSumCore(result, root, sum, path, 0);
        return result;
    }
};