
//����һ���ַ������� tokens ����ʾһ������ �沨����ʾ�� ��ʾ���������ʽ��
//�������ñ��ʽ������һ����ʾ���ʽֵ��������
//ע�⣺
//��Ч�����Ϊ '+'��'-'��'*' �� '/' ��
//ÿ����������������󣩶�������һ������������һ�����ʽ��
//��������֮��ĳ������� ����ض� ��
//���ʽ�в����������㡣
//������һ�������沨����ʾ����ʾ���������ʽ��
//�𰸼������м������������ 32 λ ������ʾ��


class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for (auto& str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (str[0])
                {
                case '+':
                    st.push(left + right); break;
                case '-':
                    st.push(left - right); break;
                case '*':
                    st.push(left * right); break;
                case '/':
                    st.push(left / right); break;
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};



//�������Ĳ������
//����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩


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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        int levelSize = 0;
        if (root) {
            q.push(root);
            levelSize = 1;
        }
        while (!q.empty()) {
            vector<int> v;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            vv.push_back(v);
            levelSize = q.size();
        }
        return vv;
    }
};