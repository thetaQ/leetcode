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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = last_visited;
        root->left = NULL;
        last_visited = root;
    }


    void flatten_2(TreeNode* root) {
        TreeNode *cur = root;
        while(cur != NULL)
        {
            if(cur->left != NULL)
            {
                TreeNode *pre = cur->left;
                while(pre->right != NULL)
                    pre = pre->right;
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
private:
    TreeNode *last_visited = NULL;
};