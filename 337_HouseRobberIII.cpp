#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    int robCore(TreeNode *root, unordered_map<TreeNode *, int>& cache)
    {
        if(root == NULL)
            return NULL;
        if(cache.count(root))
            return cache[root];
        
        int no_choose_max = robCore(root->left, cache) + robCore(root->right, cache);
        int choose_max = root->val;
        if(root->left != NULL)
        {
            choose_max += robCore(root->left->left, cache) + robCore(root->left->right, cache);
        }
        if(root->right != NULL)
        {
            choose_max += robCore(root->right->left, cache) + robCore(root->right->right, cache);
        }
        return cache[root] = max(no_choose_max, choose_max);
    }
    
    int rob(TreeNode* root)
    {
        unordered_map<TreeNode *, int> cache;
        return robCore(root, cache);
    }
};