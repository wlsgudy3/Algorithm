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

class BinarySearchTree {
	Node* root;

public:
	BinarySearchTree() = default;

	void init() {
		root = nullptr;
		node_count = 0;
	}

	void insert(int x) {
		root = insert_rec(root, x);
	}

	void remove(int x) {
		root = remove_rec(root, x);
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
	Node* insert_rec(Node* node, int x) {
		if (node == nullptr) {
			return new_node(x);
		}

		if (x < node->key) {
			node->left = insert_rec(node->left, x);
		}
		else if (x > node->key)
			node->right = insert_rec(node->right, x);

		return node;

	}

	Node* remove_rec(Node* node, int x) {
		if (node == nullptr)
			return node;
		if (x < node->key) {
			node->left = remove_rec(node->left, x);
		}
		else if (x > node->key) {
			node->right = remove_rec(node->right, x);
		}
		else {
			if (node->left == nullptr) {
				return node->right;
			}
			else if (node->right == nullptr) {
				return node->left;
			}
			else {
				const int temp = find_min_key(node->right);
				node->key = temp;
				node->right = remove_rec(node->right, temp);
			}
		}
		return node;
	}

	int find_min_key(Node* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node->key;
	}

	void traversal_rec(Node* node, int type) const {
		if (node == nullptr) return;
		if (type == 0) cout << node->key << ' ';
		traversal_rec(node->left, type);
		if (type == 1) cout << node->key << ' ';
		traversal_rec(node->right, type);
		if (type == 2) cout << node->key << ' ';
	}

};

int main() {
    BinarySearchTree tree;
}