#include <iostream>
#include <string>

using namespace std;

struct Node {
	int key;
	string text;
	int num;
	Node* left;
	Node* right;
};

constexpr int MAX_COUNT = 10000;

int node_count = 0;
Node node_pool[MAX_COUNT];
Node* memo[1000];

Node* new_node(int x) {
	node_pool[node_count].key = x;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

Node* new_node(int key, string text) {
	node_pool[node_count].key = key;
	node_pool[node_count].text = text;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

Node* new_node(int key, int num) {
	node_pool[node_count].key = key;
	node_pool[node_count].num = num;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

class Tree {
	Node* root;
	Node* temp;
	string str = "+*-/";

public:
	Tree() = default;

	void init() {
		root = nullptr;
		node_count = 0;
	}

	void insert(int key, string text, int x = 0, int y = 0) {
		Node* node;
		if (root == nullptr) {
			root = new_node(key, text);
			memo[key] = root;
			node = root;
		}
		else {
			node = memo[key];
			node->text = text;
		}
		if (x != 0) {
			node->left = new_node(x);
			memo[x] = node->left;
			if (y != 0) {
				node->right = new_node(y);
				memo[y] = node->right;
			}
		}

	}

	void insert(int key, int num, int x = 0, int y = 0) {
		Node* node;
		if (root == nullptr) {
			root = new_node(key, num);
			memo[key] = root;
			node = root;
		}
		else {
			node = memo[key];
			node->num = num;
		}
		if (x != 0) {
			node->left = new_node(x);
			memo[x] = node->left;
			if (y != 0) {
				node->right = new_node(y);
				memo[y] = node->right;
			}
		}
	}

	void check_and_print(int TC) {
		post_order_check(root);
		cout << "#" << TC << " " << root->num << '\n';
	}

private:

	void post_order_check(Node* node) {
		if (node == nullptr)
			return;
		post_order_check(node->left);
		post_order_check(node->right);
		if (node->text[0] == '+') {
			node->num = node->left->num + node->right->num;
		}
		else if (node->text[0] == '-') {
			node->num = node->left->num - node->right->num;
		}
		else if (node->text[0] == '*') {
			node->num = node->left->num * node->right->num;
		}
		else if (node->text[0] == '/') {
			node->num = node->left->num / node->right->num;
		}
	}

};

int T = 10, N, key, x, y, temp;
string s;

int main() {
	Tree tree;
	tree.init();
	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> N;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			cin >> key >> s;
			if ('0' <= s[0] && s[0] <= '9')
			{
				temp = stoi(s);
				tree.insert(key, temp);
			}
			else {
				if (cnt + 2 <= N)
				{
					cin >> x >> y;
					tree.insert(key, s, x, y);
					cnt += 2;
				}
				else if (cnt + 1 <= N) {
					cin >> x;
					tree.insert(key, s, x);
					cnt++;
				}
				else {
					tree.insert(key, s);
				}
			}
			
		}
		tree.check_and_print(test_case);
	}
	return 0;
}