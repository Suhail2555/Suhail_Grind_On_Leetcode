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

    int solve(TreeNode* root, int current) {

        // If tree is empty
        if (root == NULL) {
            return 0;
        }

        // Build the number
        current = current * 10 + root->val;

        // If leaf node
        if (root->left == NULL && root->right == NULL) {
            return current;
        }

        // Go to left and right
        int leftSum = solve(root->left, current);
        int rightSum = solve(root->right, current);

        return leftSum + rightSum;
    }


    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};