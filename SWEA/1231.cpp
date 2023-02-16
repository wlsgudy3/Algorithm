#include <iostream>

using namespace std;

struct Node {
	int key;
	char text;
	Node* left;
	Node* right;
};

constexpr int MAX_COUNT = 10000;

int node_count = 0;
Node node_pool[MAX_COUNT];

Node* new_node(int x) {
	node_pool[node_count].key = x;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

Node* new_node(int num, char text) {
	node_pool[node_count].key = num;
	node_pool[node_count].text = text;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

class Tree {
	Node* root;
	Node* temp;

public:
	Tree() = default;

	void init() {
		root = nullptr;
		node_count = 0;
	}

	void insert(int x, int text) {
		root = insert_rec(root, x, text);
	}

	void insert_text(char text, int num, int x = 0, int y = 0) {
		temp = nullptr;
		find_key(root, num);
		Node* node;
		if (temp == nullptr) {
			root = new_node(num, text);
			node = root;
		}
		else {
			node = temp;
			node->text = text;
		}

		if (x != 0) {
			node->left = new_node(x);
			if (y != 0)
				node->right = new_node(y);
		}
	}

	void print_tree(int TC) {
		Node* node = root;
		cout << "#" << TC << " ";
		in_order(node);
		cout << '\n';
	}

	void find_key(Node* node, int x) {
		if (node != nullptr) {
			find_key(node->left, x);
			if (node->key == x)
				temp = node;
			find_key(node->right, x);
		}
	}

	bool find(int x) {
		Node* node = root;
		while (node != nullptr) {
			if (node->key == x)
				return true;
			node = x < node->key ? node->left : node->right;
		}
		return false;
	}

private:
	Node* insert_rec(Node* node, int x, char text) {
		if (node == nullptr) {
			return new_node(x, text);
		}

		if (x < node->key) {
			node->left = insert_rec(node->left, x, text);
		}
		else if (x > node->key)
			node->right = insert_rec(node->right, x, text);

		return node;
	}

	void in_order(Node* node) {
		if (node == nullptr)
			return;
		in_order(node->left);
		cout << node->text;
		in_order(node->right);
	}

};

int T = 10, N, num, x, y;
char c;

int main() {
	Tree tree;
	for (int test_case = 1; test_case <= 10; test_case++) {
		tree.init();
		cin >> N;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			cin >> num >> c;
			if (cnt + 2 <= N)
			{
				cin >> x >> y;
				tree.insert_text(c, num, x, y);
				cnt += 2;
			}
			else if (cnt + 1 <= N) {
				cin >> x;
				tree.insert_text(c, num, x);
				cnt++;
			}
			else {
				tree.insert_text(c, num);
			}
		}
		tree.print_tree(test_case);
	}
	return 0;
}