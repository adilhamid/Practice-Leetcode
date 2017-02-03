#include"import.h"
using namespace std;
class TrieNode {
public:
	char val;
	bool isLeaf; // if it is end value of the prefix
	int numShared;
	vector<TrieNode*> children;
	TrieNode() :val(' '), isLeaf(false), numShared(0) {}
	TrieNode(char ch) : val(ch), isLeaf(false), numShared(0) {}

	TrieNode* subNode(char ch) {	
		if (!children.empty()) {
			for (auto child : children) {
				if (child->val == ch)
					return child;
			}
		}
		return nullptr;
	}

	~TrieNode() {
		for (auto child : children)
			delete child;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		if (search(word)) return;
		TrieNode* curr = root;
		for (auto ch : word) {
			TrieNode* child = curr->subNode(ch);
			if (child != nullptr) {
				curr = child;
			}
			else {
				TrieNode *newNode = new TrieNode(ch);
				curr->children.push_back(newNode);
				curr = newNode;
			}
			++curr->numShared;
		}
		curr->isLeaf = true;

	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* curr = root;
		for (auto ch : word) {
			curr = curr->subNode(ch);
			if (curr == nullptr)
				return false;
		}
		return curr->isLeaf == true;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* curr = root;
		for (auto ch : prefix) {
			curr = curr->subNode(ch);
			if (curr == nullptr)
				return false;
		}
		return true;
	}
	~Trie() {
		delete root;
	}

private:
	TrieNode* root;
};

int main() {
	 Trie trie;
	 trie.insert("somestring");
	 trie.insert("some");
	 cout << trie.startsWith("so");
	return 0;
}
// Your Trie object will be instantiated and called as such:
