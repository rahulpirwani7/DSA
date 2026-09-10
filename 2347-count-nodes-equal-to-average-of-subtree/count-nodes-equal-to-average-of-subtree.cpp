class Solution {
public:
    pair<int,int> solve(TreeNode* root, int& ans) {
        if (root == NULL) return {0, 0};

        auto [leftSum, leftCnt] = solve(root->left, ans);
        auto [rightSum, rightCnt] = solve(root->right, ans);

        int sum = root->val + leftSum + rightSum;
        int cnt = 1 + leftCnt + rightCnt;

        if (root->val == sum / cnt)
            ans++;

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};