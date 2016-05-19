#include <iostream>
#include <algorithm>
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
    //Solution one: recursion
    int maxDepth(TreeNode *root) 
    {
        if(root == NULL)
            return 0;
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        return max(left_max, right_max) + 1;
    }


    //Solution two: non-recursion
    int maxDepth_2(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        stack<pair<TreeNode *, int> > s;
        s.push(make_pair(root, 1));
        
        int max_depth = 0;
        while(!s.empty())
        {
            TreeNode *node = s.top().first;        
            int cur_depth = s.top().second;
            s.pop();
            max_depth = max(max_depth, cur_depth);

            if(node->right != NULL)
            {
                s.push({node->right, cur_depth + 1});
            }
            if(node->left != NULL)
            {
                s.push({node->left, cur_depth + 1});
            }
        }
        return max_depth;
    }
};


int main(void)
{
    Solution solution;
    cout << solution.maxDepth(NULL) << endl;
    return 0;
}
