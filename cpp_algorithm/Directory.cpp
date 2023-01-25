#include <iostream>

using namespace std;

struct Node {
	int name;
	Node* head;
	Node* child[30];
	int count;
};

constexpr int MAX_COUNT = 100000;
int node_count = 0;
Node node_pool[MAX_COUNT] ;

Node* new_node(char name) {
	node_pool[node_count].name = name;
	node_pool[node_count].count = 0;
	return &node_pool[node_count++];
}

class Tree {
	Node* root;
public:
	void init(int n) { // n은 어디에?
		root = new_node('/');
		node_count = 0;
	}

	void cmd_mkdir(char path[2000], char name[7]) {
		Node* node = root;
		int i = 1;
		while (path[i] != '\0') {
			int temp = 0;
			while (path[i] != '/') {
				temp = ((temp << 5) | (path[i] - 'a'));
				i++;
			}
			for (int k = 0; k < 30; k++)
				if (node->child[k]->name == temp)
					node = node->child[k];
			i++;
		}
		i = 0;
		int name_int = 0;
		while (name[i] != '\0') {
			name_int = ((name_int << 5) | (path[i] - 'a'));
			i++;
		}
		int cnt = 0;
		while (node->child[cnt++] != nullptr);
		node->child[cnt] = new_node(name_int);
		node->child[cnt]->head = node;
		while (node != nullptr) {
			node->count += 1;
			node = node->head;
		}
	}

	void cmd_rm(char path[2000]) {
		Node* node = root;
		int i = 1;
		while (path[i] != '\0') {
			int temp = 0;
			while (path[i] != '/') {
				temp = ((temp << 5) | (path[i] - 'a'));
				i++;
			}
			for (int k = 0; k < 30; k++)
				if (node->child[k]->name == temp)
					node = node->child[k];
			i++;
		}
		Node* temp = node;
		node = node->head;
		for (int i = 0; i < 30; i++) {
			if (node->child[i] == temp) {
				node->child[i] = nullptr;
				int rm_cnt = temp->count + 1;
				while (node != nullptr) {
					node->count -= rm_cnt;
					node = node->head;
				}
				break;
			}
		}
	}
	
	void cmd_cp(char srcPath[2000], char dstPath[2000]) {
		Node* node1 = root;
		Node* node2 = root;
		int i = 1;
		while (srcPath[i] != '\0') {
			int temp = 0;
			while (srcPath[i] != '/') {
				temp = ((temp << 5) | (srcPath[i] - 'a'));
				i++;
			}
			for (int k = 0; k < 30; k++)
				if (node1->child[k]->name == temp)
					node1 = node1->child[k];
			i++;
		}
		i = 1;
		while (dstPath[i] != '\0') {
			int temp = 0;
			while (dstPath[i] != '/') {
				temp = ((temp << 5) | (dstPath[i] - 'a'));
				i++;
			}
			for (int k = 0; k < 30; k++)
				if (node2->child[k]->name == temp)
					node2 = node2->child[k];
			i++;
		}


	}

	void cmd_mv(char srcPath[2000], char dstPath[2000]) {
		Node* node1 = root;
		Node* node2 = root;
		int i = 1;
		while (srcPath[i] != '\0') {
			int temp = 0;
			while (srcPath[i] != '/') {
				temp = ((temp << 5) | (srcPath[i] - 'a'));
				i++;
			}
			for (int k = 0; k < 30; k++)
				if (node1->child[k]->name == temp)
					node1 = node1->child[k];
			i++;
		}
		i = 1;
		while (dstPath[i] != '\0') {
			int temp = 0;
			while (dstPath[i] != '/') {
				temp = ((temp << 5) | (dstPath[i] - 'a'));
				i++;
			}
			for (int k = 0; k < 30; k++)
				if (node2->child[k]->name == temp)
					node2 = node2->child[k];
			i++;
		}

		int rm_cnt = node1->count + 1;
		Node* temp = node1;
		node1 = node1->head;
		for (int i = 0; i < 30; i++) {
			if (node1->child[i] == temp) {
				node1->child[i] = nullptr;
				while (node1 != nullptr) {
					node1->count -= rm_cnt;
					node1 = node1->head;
				}
				break;
			}
		}
		int cnt = 0;
		while (node2->child[cnt++] == nullptr);
		node2->child[cnt] = temp;
		while (node2 == nullptr) {
			node2->count += rm_cnt;
			node2 = node2->head;
		}
	}

	int cmd_find(char path[2000]) {
		Node* node = root;
		int i = 1;
		while (path[i] != '\0') {
			int temp = 0;
			while (path[i] != '/') {
				temp = ((temp << 5) | (path[i] - 'a'));
				i++;
			}
			for (int k = 0; k < 30; k++)
				if (node->child[k]->name == temp)
					node = node->child[k];
			i++;
		} // 해당 패스 노드로 이동 node = 해당 패스 노드
		return node->count;
	}

};