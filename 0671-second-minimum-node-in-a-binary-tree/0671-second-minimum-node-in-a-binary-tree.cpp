/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long ans = LLONG_MAX;

    void dfs(TreeNode* root, int minVal) {
        if (root == NULL)
            return;

        if (root->val > minVal) {
            ans = min(ans, (long long)root->val);
        }

        dfs(root->left, minVal);
        dfs(root->right, minVal);
    }

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root, root->val);

        if (ans == LLONG_MAX)
            return -1;

        return (int)ans;
    }
};