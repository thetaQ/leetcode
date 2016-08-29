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
    
    vector<TreeNode *> generateTreesCore(int start, int end)
    {
        vector<TreeNode *> res;
        if(start > end)
        {
            res.push_back(NULL);
            return res;
        }
        if(start == end)
        {
            res.push_back(new TreeNode(start));
            return res;
        }
        for(int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = generateTreesCore(start, i - 1);
            vector<TreeNode *> right = generateTreesCore(i + 1, end);
            for(TreeNode *l : left)
            {
                for(TreeNode *r : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n)
    {
        if(n == 0)
            return vector<TreeNode *>();
        return generateTreesCore(1, n);
    }
};