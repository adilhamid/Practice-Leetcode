#include<iostream>
#include<algorithm>
#include<vector>
#include <set>
#include<map>
#include<unordered_map>



using namespace std;


class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		
		map < string , multiset<string> > hashmap;
		
		for (int i = 0; i < strs.size(); i++) {
			//string t = strs[i];

			string t = strSort(strs[i]);
			//sort(t.begin(), t.end()); // takes nlogn times we can reduce using the counting sort.

			hashmap[t].insert(strs[i]);
		}
		vector< vector<string>> result(hashmap.size());
		int cnt = 0;
		for (auto m : hashmap) {
			vector<string> tempVal(m.second.begin(), m.second.end());
			result[cnt++] = tempVal;
		}
		return result;
		}

	string strSort(string s) {

		int count[26] = { 0 }, n = s.length();
		for (int i = 0; i < n; i++)
			count[s[i] - 'a']++;
		int p = 0;
		string t(n, 'a');
		for (int j = 0; j < 26; j++)
			for (int i = 0; i < count[j]; i++)
				t[p++] += j;
		return t;
	}

};


int main() {

	Solution obj;


	return 0;
}