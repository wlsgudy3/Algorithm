#include <iostream>
#include <string>

using namespace std;

struct Node {
	int key;
	string text;
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

Node* new_node(int num, string text) {
	node_pool[node_count].key = num;
	node_pool[node_count].text = text;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

class Tree {
	Node* root;
	Node* temp;
	int check = 0;
	string str = "+*-/";

public:
	Tree() = default;

	void init() {
		root = nullptr;
		node_count = 0;
	}

	void insert_text(string text, int num, int x = 0, int y = 0) {
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
	int check_and_print(int TC) {
		check = 1;
		post_order_check(root);
		if (check == 0)
			cout << "#" << TC << " " << check << '\n';
		else
			cout << "#" << TC << " " << check << '\n';
	}

	void find_key(Node* node, int x) {
		if (node != nullptr) {
			find_key(node->left, x);
			find_key(node->right, x);
			if (node->key == x)
				temp = node;
		}
	}

private:

	void post_order_check(Node* node) {
		if (node == nullptr)
			return;
		post_order_check(node->left);
		if (node->left == nullptr && node->right == nullptr)
		{
			if (str.find(node->text[0]) != string::npos)
				check = 0;
		}
		else {
			if ('0' <= node->text[0] && node->text[0] <= '9')
				check = 0;
		}
		post_order_check(node->right);
	}

};

int T = 10, N, num, x, y;
string s;

int main() {
	Tree tree;
	for (int test_case = 1; test_case <= 10; test_case++) {
		tree.init();
		cin >> N;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			cin >> num >> s;
			if (cnt + 2 <= N)
			{
				cin >> x >> y;
				tree.insert_text(s, num, x, y);
				cnt += 2;
			}
			else if (cnt + 1 <= N) {
				cin >> x;
				tree.insert_text(s, num, x);
				cnt++;
			}
			else {
				tree.insert_text(s, num);
			}
		}
		tree.check_and_print(test_case);
	}
	return 0;
}