#include <iostream>
#include <cstring>

using namespace std;

size_t djb2(const char* str) {
	size_t hash = 5381;
	for (; *str; ++str) {
		hash = ((hash << 5) + hash) + *str;
	}

	return hash;
}

constexpr size_t MAX_N = 10000;
constexpr size_t MAX_LEN = 10;

struct Node {
	char str[MAX_LEN + 1];
	int data;
	Node* next;
};

int node_count = 0;
Node nodes[MAX_N];

Node* new_node(const char str[MAX_LEN + 1], int data) {
	strcpy(nodes[node_count].str, str);
	nodes[node_count].data = data;
	nodes[node_count].next = nullptr;

	return &nodes[node_count++];
}

class HashMap {
	static constexpr size_t TABLE_SIZE = 1 << 12;
	static constexpr size_t DIV = TABLE_SIZE - 1;

	Node hash_table[TABLE_SIZE];

public: HashMap() = default;

	  void init() {
		  memset(hash_table, 0, sizeof hash_table);
		  node_count = 0;
	  }

	  void insert(const char str[MAX_LEN + 1], int data) {
		  Node* const prev_node = get_prev_node(str);
		  if (prev_node->next == nullptr)
			  prev_node->next = new_node(str, data);
		  else
			  prev_node->next->data = data;
	  }

	  void remove(const char str[MAX_LEN + 1]) {
		  Node* const prev_node = get_prev_node(str);
		  if (prev_node->next != nullptr)
			  prev_node->next = prev_node->next->next;
	  }

	  Node* get(const char str[MAX_LEN + 1]) {
		  return get_prev_node(str)->next;
	  }

private:
	Node* get_prev_node(const char str[MAX_LEN + 1]) {
		Node* prev_ptr = &hash_table[djb2(str) & DIV];
		while (prev_ptr->next != nullptr && strcmp(prev_ptr->next->str, str) != 0)
			prev_ptr = prev_ptr->next;
		return prev_ptr;
	}
};

int main() {
	HashMap hash_map{};
	// 0 : 초기화
	// 1 str x : (str, x) 삽입 (이미 str이 있는 경우 data를 x로 교체)
	// 2 str : str 삭제 (str이 없는 경우 무시)
	// 3 str : str 검색

	int cmd, x;
	char str[MAX_LEN + 1];
	Node* ptr;
	for (;;) {
		cin >> cmd;
		switch (cmd) {
		case 0:
			hash_map.init();
			break;
		case 1:
			cin >> str >> x;
			if (strlen(str) > MAX_LEN) return cout << "invalid key length\n", 0;
			hash_map.insert(str, x);
			break;
		case 2:
			cin >> str;
			if (strlen(str) > MAX_LEN) return cout << "invalid key length\n", 0;
			hash_map.remove(str);
			break;
		case 3:
			cin >> str;
			if (strlen(str) > MAX_LEN) return cout << "invalid key length\n", 0;
			ptr = hash_map.get(str);
			if (ptr == nullptr)
				cout << "not found\n";
			else {
				cout << str << ":" << ptr->data << '\n';
			}
			break;
		default:
			return cout << "invalid command\n", 0;
		}
	}
}