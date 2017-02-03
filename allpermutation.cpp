#include"import.h"

using namespace std;


void permute(string str, int l, int r, int k) {
	int i;
	if (l == r || r-l == k) {
		cout << str << " ";
	}
	else {
		for (int i = l; i <= r; i++) {
			swap(str[l], str[i]);
			permute(str, l + 1, r,k);
			swap(str[l], str[i]); //backtrack the initial step
		}
	}
}


int main() {

	string str = "ABC";
	permute(str, 0, str.length() - 1, 2);
	return 0;
}