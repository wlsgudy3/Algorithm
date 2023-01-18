#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* new_node(int data) {
	Node* node = new Node;

	node->data = data;
	node->next = nullptr;

	return node;
}

constexpr size_t MAX_NODE = 10000;

int node_count = 0;
Node node_pool[MAX_NODE];

Node* new_node(int data) {
	node_pool[node_count].data = data;
	node_pool[node_count].next = nullptr;

	return &node_pool[node_count++];
}