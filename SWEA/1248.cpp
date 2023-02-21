#include <iostream>

using namespace std;

struct Node {
	Node* head;
	Node* right;
	Node* left;
	int key;
};

constexpr int MAX_COUNT = 10005;

int node_count = 0;
Node node_pool[MAX_COUNT];
Node* memo[MAX_COUNT];
int cnt_memo[MAX_COUNT];

Node* new_node(int key) {
	node_pool[node_count].key = key;
	node_pool[node_count].head = nullptr;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

class Tree {
	Node* root;
public:
	void init() {
		root = nullptr;
		node_count = 0;
	}

	void insert(int parent, int child) {
		if (memo[parent] == nullptr) {
			memo[parent] = new_node(parent);
		}
		Node* parent_node = memo[parent];
		if (memo[child] == nullptr)
			memo[child] = new_node(child);
		Node* child_node = memo[child];
		if (parent_node->left == nullptr) {
			parent_node->left = child_node;
			child_node->head = parent_node;
		}
		else if (parent_node->right == nullptr) {
			parent_node->right = child_node;
			child_node->head = parent_node;
		}
	}

	int common_anc(int a, int b) {
		bool a_anc[10005] = { false };

		Node* temp = memo[a];
		while (temp->key != 1) {
			a_anc[temp->head->key] = true;
			temp = temp->head;
		}
		temp = memo[b];
		while (!a_anc[temp->head->key]) {
			temp = temp->head;
		}
		return temp->head->key;
	}

	int tree_cnt(int anc) {
		int cnt = 1;
		if (memo[anc]->left != nullptr) {
			cnt += tree_cnt(memo[anc]->left->key);
			if (memo[anc]->right != nullptr)
				cnt += tree_cnt(memo[anc]->right->key);
		}
		return cnt;
	}
};


int T, V, E, a, b;

int main() {
	int p, c, common, subcnt;
	Tree tree;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		tree.init();
		cin >> V >> E >> a >> b;
		int n = 1;
		while (memo[n] != 0)
			memo[n++] = 0;
		for (int i = 0; i < E; i++) {
			cin >> p >> c;
			tree.insert(p, c);
		}
		common = tree.common_anc(a, b);
		subcnt = tree.tree_cnt(common);
		cout << '#' << TC << ' ' << common << ' ' << subcnt << '\n';
	}
	return 0;
}