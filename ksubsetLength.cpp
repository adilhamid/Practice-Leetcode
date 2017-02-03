#include"import.h"

using namespace std;


void getSubsets(vector<int> superSet, int k, int idx, vector<int>& curr, vector<vector<int>>& solution) {
	if (curr.size() == k) {
		solution.push_back(curr);
		return;
	}

	if (idx == superSet.size()) {
		return;
	}

	int val = superSet[idx];
	curr.push_back(val);

	getSubsets(superSet, k, idx + 1, curr, solution);
	curr.pop_back();
	getSubsets(superSet, k, idx + 1, curr, solution);

}


int main() {
	
	vector<int> numbers({1,2,3,4,5,6});

	//for (int nums : numbers) cout << nums << " ";

	int k = 3;
	vector<int> current;
	vector<vector<int>> result;

	getSubsets(numbers, k, 0, current, result);
	cout << result.size() << endl;
	for (auto sets : result) {
		for (int nums : sets) {
			cout << nums << " ";
		}
		cout << endl;
	}

	return 0;
}