#include"import.h"
using namespace std;

class Solution {
private:
	vector<vector<int>> visitedMat;
	int maxLen;
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {

		visitedMat.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
		maxLen = 1;
		for (int i = 0; i< matrix.size(); i++) {
			for (int j = 0; j<matrix[0].size(); j++) {
				cout << maxLength(matrix, i, j)<<" ";
			}
			cout << endl;
		}

		return maxLen;

	}

	int maxLength(vector<vector<int>>& mat, int i, int j) {
		if (visitedMat[i][j] != -1) return visitedMat[i][j];

		int localMax = 1;
		visitedMat[i][j] = 1;
		//Check for the four directions with longest 
		if (i>0 && mat[i-1][j] > mat[i][j]) {
			localMax = max(1 + maxLength(mat, i - 1, j), localMax);
		}
		if (j>0 && mat[i][j-1] > mat[i][j]) {
			localMax = max(1 + maxLength(mat, i, j - 1), localMax);
		}
		if (i<mat.size() - 1 && mat[i + 1][j] > mat[i][j]) {
			localMax = max(1 + maxLength(mat, i + 1, j), localMax);
		}
		if (j<mat[0].size() - 1 && mat[i][j + 1] > mat[i][j]) {
			localMax = max(1 + maxLength(mat, i, j + 1), localMax);
		}

		visitedMat[i][j] = max(localMax, visitedMat[i][j]);
		maxLen = max(localMax, maxLen);

		return localMax;
	}
};

int main() {
	Solution solObj;
	vector<vector<int>> map;
	//[[9,9,4],[6,6,8],[2,1,1]] // [[3,4,5],[3,2,6],[2,2,1]]
	map.push_back({3,4,5});
	map.push_back({3,2,6 });
	map.push_back({2,2,1});
	cout << solObj.longestIncreasingPath(map);
}