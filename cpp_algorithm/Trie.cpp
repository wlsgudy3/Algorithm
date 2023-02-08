#include <iostream>
#include <vector>


class Trie {
	static constexpr size_t M = 26;
	static constexpr char OFFSET = 'a';

	struct TrieNode {
		int child[M];
		bool is_terminal;

		TrieNode() {
			std::memset(child, -1, sizeof(int) * M);
			is_terminal = false;
		}
	};

	std::vector<TrieNode> nodes;

public:
	Trie() : nodes(1) {};

	void init() {
		nodes.resize(1);
		nodes[0] = TrieNode();
	}

	void insert(const std::string str) {
		int node_id = 0;
		for (const auto& c : str) {
			if (nodes[node_id].child[c - OFFSET] == -1) {
				nodes[node_id].child[c - OFFSET] = nodes.size();
				nodes.emplace_back();
			}
			node_id = nodes[node_id].child[c - OFFSET];
		}
		nodes[node_id].is_terminal = true;
	}

	void remove(const std::string str) {
		int node_id = 0;
		for (const auto& c : str) {
			if (nodes[node_id].child[c - OFFSET] == -1) {
				return;
			}
			node_id = nodes[node_id].child[c - OFFSET];
		}
		nodes[node_id].is_terminal = false;
	}

	bool find(const std::string str) const {
		int node_id = 0;
		for (const auto& c : str) {
			if (nodes[node_id].child[c - OFFSET] == -1)
				return false;
			node_id = nodes[node_id].child[c - OFFSET];
		}
		return nodes[node_id].is_terminal;
	}

};
