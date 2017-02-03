#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>


using namespace std;


class Solution {
public:
	double myPow(double x, int n) {

		if (n == 0) return 1;

		double resAns = 1.0;

		if (n < 0) {
			n = -n;
			x = 1 / x;
		}

		while (n > 0) {
			if (n & 1) resAns *= x;
			x *= x;
			n >>= 1;

		}
		return resAns;

	}
};

int main() {

	Solution obj;
	cout << obj.myPow(25.03, -5) << endl;
	return 1;
}