//993https://leetcode-cn.com/problems/cousins-in-binary-tree/

class Solution {
public:
    using PTT = pair<TreeNode*, TreeNode*>;
    bool isCousins(TreeNode* root, int x, int y) {
        // ʹ�ö���q������bfs
        // ����pair�У�p.first ��¼��ǰ����ָ�룬p.second ��¼��ǰ���ĸ�����ָ��
        queue<PTT> q;
        q.push({ root, nullptr });
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> rec_parent;
            for (int i = 0; i < n; i++) {
                auto [cur, parent] = q.front(); q.pop();
                if (cur->val == x || cur->val == y)
                    rec_parent.push_back(parent);
                if (cur->left) q.push({ cur->left, cur });
                if (cur->right) q.push({ cur->right, cur });
            }
            // `x` �� `y` ��û����
            if (rec_parent.size() == 0)
                continue;
            // `x` �� `y` ֻ����һ��
            else if (rec_parent.size() == 1)
                return false;
            // `x` �� `y` ��������
            else if (rec_parent.size() == 2)
                // `x` �� `y` ���ڵ� ��ͬ/����ͬ ��
                return rec_parent[0] != rec_parent[1];
        }
        return false;
    }
};
