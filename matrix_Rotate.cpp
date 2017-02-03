#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>


using namespace std;


class Solution{
public:
	void printMat(vector<vector <int>> matrix) {

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}


	void printVector(vector <int> vec) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		return;
	}

	void rotate(vector<vector <int>> & matrix) {
		
		int Rows = matrix.size();
		int Cols = matrix[0].size();
		
		//cout << Rows << " " << Cols << endl;
		int K = Rows / 2; 
		for (int k = 0; k < K; k++) {
			int row =  k ;
			int col =  k ;
			for (int cnt = 0  ; cnt < Cols - 1 - (2*k); cnt++) {
				int tempvalOne = matrix[row + cnt][Cols - 1 - k];
				matrix[row +cnt ][Cols - 1 - k] = matrix[row][col + cnt];
				int tempvalTwo = matrix[Rows - 1 - k][Cols - 1 - k - cnt ];
				matrix[Rows - 1 - k][Cols - 1 - k -cnt ] = tempvalOne;
				tempvalOne = matrix[Rows - 1 - k -cnt ][col];
				matrix[Rows - 1 - k -cnt][col] = tempvalTwo;
				
				matrix[row][col + cnt ] = tempvalOne;
			}
		}
		printMat(matrix);

	}

	 vector<int> spiralOrder(vector<vector<int>>& mat) {

		 int M = mat.size(), N = mat[0].size();
		 vector<int> result(M*N);

		 int rowStart = 0;
		 int rowEnd = M - 1;
		 int colStart = 0;
		 int colEnd = N - 1;
		 int cnt = 0;
		 while (rowStart <= rowEnd && colStart <= colEnd) {

			 // Horizontal From Left to Right
			 for (int col = colStart; col <= colEnd; col++) {
				 result[cnt++] = mat[rowStart][col];
			 }
			 if (++rowStart >rowEnd) break;

			 //Vertical Top to Bottom
			 for (int row = rowStart; row <= rowEnd; row++) {
				 result[cnt++] = mat[row][colEnd];
			 }
			 if (--colEnd<colStart) break;

			 //Horizontal Right to Left
			 for (int col = colEnd; col >= colStart; col--) {
				 result[cnt++] = mat[rowEnd][col];
			 }
			 if (--rowEnd < rowStart) break;

			 //vertical up from the left

			 for (int row = rowEnd; row >= rowStart; row--) {
				 result[cnt++] = mat[row][colStart];
			 }
			 if (++colStart > colEnd) break;

		 }

		 return result;

	}
};



int main() {

	int i = 9;

	cout << (i >> 1) << endl;
	exit(0);

	vector<vector<int>> newmat(4, vector<int> (4));
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newmat[i][j] = ++count;
		}
	}
	//printMat(newmat);

	Solution obj;

	vector<int> res = obj.spiralOrder(newmat);
	obj.printVector(res);

	return 0;

}