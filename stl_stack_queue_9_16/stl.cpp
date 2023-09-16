#include <iostream>
using namespace std;
#include <stack>
#include <queue>

void test_stack()
{
	stack<int> st;
	for (size_t i = 0; i < 10; ++i) {
		st.push((int)i);
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}
void test_queue()
{
	queue<int> qe;
	for (size_t i = 0; i < 10; ++i) {
		qe.push(i);
	}
	while (!qe.empty()) {
		cout << qe.front() << " ";
		qe.pop();
	}
}
int main()
{
	test_stack();
	cout << endl << "================================" << endl;
	test_queue();
	return 0;
}


//���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//
//ʵ�� MinStack �� :
//
//MinStack() ��ʼ����ջ����
//void push(int val) ��Ԫ��val�����ջ��
//void pop() ɾ����ջ������Ԫ�ء�
//int top() ��ȡ��ջ������Ԫ�ء�
//int getMin() ��ȡ��ջ�е���СԪ�ء�


class MinStack {
public:
    MinStack() {}

    void push(int val) {
        _st.push(val);
        if (_minst.empty() || val <= _minst.top())
        {
            _minst.push(val);
        }
    }

    void pop() {
        if (_st.top() == _minst.top())
        {
            _minst.pop();
        }
        _st.pop();
    }

    int top() {
        return _st.top();
    }

    int getMin() {
        return _minst.top();
    }
private:
    stack<int> _st;
    stack<int> _minst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




//����
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳��
//����4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С�
//1. 0 <= pushV.length == popV.length <= 1000
//2. - 1000 <= pushV[i] <= 1000
//3. pushV ���������־�����ͬ


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
    {
        // write code here
        stack<int> st;
        int pushi = 0, popi = 0;
        while (pushi < pushV.size())
        {
            st.push(pushV[pushi++]);
            while (!st.empty() && st.top() == popV[popi])
            {
                st.pop();
                popi++;
            }
        }
        return st.empty();
    }
};