#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

constexpr size_t MAX_NODE = 100000;

int node_count = 0;
Node node_pool[MAX_NODE];

Node* new_node(int data) {
	node_pool[node_count].data = data;
	node_pool[node_count].next = nullptr;

	return &node_pool[node_count++];
}

class SinglyLinkedList {
	Node head, tail;

public:
	SinglyLinkedList() = default;

	void init() {
		head.next = nullptr;
		node_count = 0;
	}

	void insert(int x) {
		Node* node = new_node(x);
		Node* ptr = &head;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = node;
	}

	void I(int x, int y) {
		Node* ptr = &head;
		Node* node;
		int temp;
		for (int i = 0; i < x; i++) {
			ptr = ptr->next;
		}
		for (int i = 0; i < y; i++) {
			cin >> temp;
			node = new_node(temp);
			node->next = ptr->next;
			ptr->next = node;
			ptr = ptr->next;
		}
	}

	void D(int x, int y) {
		Node* ptr = &head;
		for (int i = 0; i < x; i++) {
			ptr = ptr->next;
		}
		for (int i = 0; i < y; i++) {
			ptr->next = ptr->next->next;
		}
	}

	void A(int y) {
		int s;
		for (int i = 0; i < y; i++) {
			cin >> s;
			insert(s);
		}
	}

	void print10(int t) const {
		Node* ptr = head.next;
		cout << "#" << t;
		for (int i = 0; i < 10; i++) {
			cout << " " << ptr->data;
			ptr = ptr->next;
		}
		cout << '\n';
	}

	void print() const {
		Node* ptr = head.next;
		cout << "[List]";
		while (ptr != nullptr) {
			cout << ptr->data << " ";
			if (ptr->next != nullptr)
				cout << "-> ";
			ptr = ptr->next;
		}
		cout << '\n';
	}
};

int N, M, num, x, y;
char order;

int main() {
	SinglyLinkedList slist;
	int T = 10;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		slist.init();
		for (int i = 0; i < N; i++) {
			cin >> num;
			slist.insert(num);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> order;
			switch (order) {
			case 'I':
				cin >> x >> y;
				slist.I(x, y);
				break;

			case 'D':
				cin >> x >> y;
				slist.D(x, y);
				break;
			case 'A':
				cin >> y;
				slist.A(y);
				break;
			}
		}
		slist.print10(tc + 1);
	}
	return 0;
}