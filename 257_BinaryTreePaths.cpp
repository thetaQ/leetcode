#include <iostream>
#include <string>
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
    void helper(TreeNode *root, string path, vector<string>& result)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            //leaf node
            result.push_back(path + to_string(root->val));
        }
        helper(root->left, path + to_string(root->val) + "->", result);
        helper(root->right, path + to_string(root->val) + "->", result);
    }

    vector<string> binaryTreePaths(TreeNode *root) 
    {
        vector<string> result;
        string path = "";
        helper(root, path, result);
        return result;
    }
};