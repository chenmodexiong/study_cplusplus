#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode {
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
	BSTreeNode(const K& key) :_left(nullptr), _right(nullptr), _key(key) {}
};

template<class K> 
class BSTree {
	typedef BSTreeNode<K> Node;
public:
	BSTree() : _root(nullptr) {}	
	bool Insert(const K& key) 
	{
		if (_root == nullptr) {
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_key < key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key) {
				parent = cur;
				cur = cur->_left;
			}
			else // 找到了 
			{
				// 左为空
				if (cur->_left == nullptr)
				{
					if (cur == _root) {
						_root = cur->_right;
					}
					else
					{
						if (parent->_right == cur) {
							parent->_right = cur->_right;
						}
						else {
							parent->_left = cur->_right;
						}
					}
				}// 右为空
				else if (cur->_right == nullptr)
				{
					if (cur == _root) {
						_root = cur->_left;
					}
					else
					{
						if (parent->_right == cur) {
							parent->_right = cur->_left;
						}
						else {
							parent->_left = cur->_left;
						}
					}
				} // 左右都不为空 
				else
				{
					// 找替代节点
					Node* parent = cur;
					Node* leftMax = cur->_left;
					while (leftMax->_right) {
						parent = leftMax;
						leftMax = leftMax->_right;
					}
					swap(cur->_key, leftMax->_key);
					if (parent->_left == leftMax) {
						parent->_left = leftMax->_left;
					}
					else {
						parent->_right = leftMax->_left;
					}
					cur = leftMax;
				}
				delete cur;
				return true;
			}
		}
		return false;
	}
	void InOrder() {
		_InOrder(_root);
	}
	void _InOrder(Node* root) {
		if (root == NULL) return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root;
};
void TestBSTree1() {
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto e : a) {
		t.Insert(e);
	}
	t.InOrder();
}
int main() {

	TestBSTree1();
	return 0;
}
