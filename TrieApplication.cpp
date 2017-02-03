#include "import.h"
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

class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void addWord(string word) {
		//if (searchWord(word)) return;
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
	bool searchWord(string word) {
		TrieNode* curr = root;
		for (auto ch : word) {
			curr = curr->subNode(ch);
			if (curr == nullptr)
				return false;
		}
		return curr->isLeaf == true;
	}

	bool search(string word) {
		return query(word, root);
	}

	bool query(string word, TrieNode* node) {
		if (!node) return false;
		TrieNode* curr = node;
		int i = 0;
		for (auto ch : word) {
			i++;
			if (ch != '.' && curr) {
				curr = curr->subNode(ch);
			}
			else if (ch == '.' && curr) {

				TrieNode* tmp = curr;
				if (!tmp->children.empty()) {
					for (auto child : tmp->children) {
						curr = child;// ->subNode(child->val);
						if (query(word.substr(i), child))
							return true;
					}
				}
				else {
					curr = nullptr;
					break;
				}
			}
			else break;
		}
		return curr && curr->isLeaf == true;
	}

	bool startsWith(string prefix) {
		TrieNode* curr = root;
		for (auto ch : prefix) {
			curr = curr->subNode(ch);
			if (curr == nullptr)
				return false;
		}
		return true;
	}
	~WordDictionary() {
		delete root;
	}

private:
	TrieNode* root;
};




int main() {
	WordDictionary word;
	word.addWord("a");
	word.addWord("a");
	//word.addWord("a");
	//word.addWord("a");
	//word.search(".");
	//word.search("a");
	//word.search("aa");
	//word.search("a");
	//word.search(".a");
	cout << word.search("a.");
}