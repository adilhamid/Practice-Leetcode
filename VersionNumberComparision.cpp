class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> value1 = findVal(version1);
		vector<int> value2 = findVal(version2);

		if (value1.size() > value2.size()) {
			value2.resize(value1.size(), 0);
		}
		else {
			value1.resize(value2.size(), 0);
		}

		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i< value1.size(); i++) {
			sum1 += sum1 * 10 + value1[i];
			sum2 += sum2 * 10 + value2[i];
		}

		if (sum1>sum2) {
			return 1;
		}
		else if (sum1 == sum2) {
			return 0;
		}
		else {
			return -1;
		}

	}

	vector<int> findVal(string str) {
		int len = str.length();
		if (!len) return{};
		vector<int> mylist;
		int prev = 0;
		for (int i = 0; i<len; i++) {
			if (str[i] == '.') {
				mylist.push_back(stoi(str.substr(prev, i - prev)));
				prev = i + 1;
			}
		}
		if (prev != len) {
			mylist.push_back(stoi(str.substr(prev)));
		}

		return mylist;
	}
};