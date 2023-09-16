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


//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//实现 MinStack 类 :
//
//MinStack() 初始化堆栈对象。
//void push(int val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//int top() 获取堆栈顶部的元素。
//int getMin() 获取堆栈中的最小元素。


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




//描述
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，
//序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，
//但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。
//1. 0 <= pushV.length == popV.length <= 1000
//2. - 1000 <= pushV[i] <= 1000
//3. pushV 的所有数字均不相同


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
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