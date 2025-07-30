class Solution {
public:
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int robbed = node->val + left.first + right.first;
        int not_robbed = max(left.first, left.second) + max(right.first, right.second);

        return {not_robbed, robbed};
    }

    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};
