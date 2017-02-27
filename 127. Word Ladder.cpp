class Solution {
public:
struct Node
{
	string word;
	int dist;
	Node(string w, int d) :word(w), dist(d) {}
};

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> dict;
	unordered_set<string> history; 
	for (auto it : wordList)
		dict.insert(it);
	if (!dict.count(endWord))
		return 0;
	queue<Node> table;
	table.push(Node(beginWord,1));
	history.insert(beginWord);
	while (!table.empty())
	{
		Node curr = table.front();
		table.pop();
		string currWord = curr.word;
		for (int i = 0; i < currWord.size(); i++)
		{
			string tmp = currWord;
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (tmp[i] == c)
					continue;
				tmp[i] = c;
				if (tmp == endWord)
					return curr.dist + 1;
				else if (!history.count(tmp) && dict.count(tmp))
				{
					history.insert(tmp);
					table.push(Node(tmp,curr.dist+1));
				}
			}
		}
	}
	return 0;
}
};