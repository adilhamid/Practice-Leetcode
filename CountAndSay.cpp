//============================================================================
// Name        : LeetcodePractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <sstream>
#include <set>


using namespace std;


string countAndSay(int num) {
	vector<int> result;
	int count = 0;
	int n = num;
	int prev_val = n % 10;
	n = n / 10;
	count = 1;
	std::stringstream finalResult;	
	while (n>0) {
		int remainder = n % 10;
		n = n / 10;
		if (prev_val == remainder && count < 2) {
			count++;
		}
		else { //
			result.insert(result.begin(), prev_val);
			result.insert(result.begin(), count);
			prev_val = remainder;
			count = 1;
		}
	}
	result.insert(result.begin(), prev_val);
	result.insert(result.begin(), count);
	
	vector<int> newresult;
	for (int cnt = 1; cnt < num; cnt++) {
		newresult = result;
		result.clear();
		prev_val = newresult[newresult.size()-1];
		count = 1;
		
		for (int rescnt = newresult.size()-2; rescnt >= 0; rescnt--) {
			int newval = newresult[rescnt];
			if (prev_val == newval && count < 2) {
				count++;
			}
			else { //
				result.insert(result.begin(), prev_val);
				result.insert(result.begin(), count);
				prev_val = newval;
				count = 1;
			}
		}
		result.insert(result.begin(), prev_val);
		result.insert(result.begin(), count);
	}
	
	std::copy(result.begin(), result.begin() + num, std::ostream_iterator<int>(finalResult, ""));
	return finalResult.str().c_str();
}

vector < vector<int> > list;
vector<int > temp;

void combinationSumUtil(vector<int>& candidates, int target, int start,  int curr_sum, vector<int> temp) {
	
	if (curr_sum == target) {
		list.push_back(temp);
		return;
	}
	if (curr_sum > target)
		return;

	for (int i = start; i < candidates.size(); i++) { 
			if (candidates[i] + curr_sum <= target) {
				//curr_sum += candidates[i];
				temp.push_back(candidates[i]);
				combinationSumUtil(candidates, target, i, curr_sum+candidates[i], temp);
				temp.pop_back();
			}
		}
	return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	
	sort(candidates.begin(), candidates.end());
	combinationSumUtil(candidates, target,0, 0, temp);

	return list;


}

#include <bitset>

string reverseBits(uint32_t n) {

	std::bitset<32> foo(n);

	cout << n <<" "<< foo.to_string() << endl;
	int maxSize = 32;
	int digitOne, digitTwo;
	for (int i = 0; i< 32 / 2; i++) {
		bool bitN = foo.test(i);
		bool bitN1 = foo.test(maxSize-1 - i);

		if (bitN == bitN1)
			continue;
		else {
			foo.flip(i);
			foo.flip(maxSize-1 - i);
		}
	}

	cout << foo.to_ulong() << " " << foo.to_string() << endl;
	return foo.to_string();
}

#include <math.h>

vector<int> grayCode(int n) {
	const int bitsCount = n;
	bitset<32> bitNum(0);

	int combinations = (int)pow(2, bitsCount);
	vector<int> result(combinations);
	result[0] = (int)bitNum.to_ulong();

	for (int i = 1; i< combinations; i++) {

		bitNum.flip(i%bitsCount);
		result[i] = (int)bitNum.to_ulong();

	}

	return result;

}

string add_strings(vector<string> sums) {
	string result;
	int max_row = sums[sums.size()-1].length();
	for (int i = 0; i < sums.size(); i++) {
		if (sums[i].length() < max_row)
		{
			int cnt = max_row - sums[i].length();
			while (cnt > 0) {
				sums[i] += 0 + 48;
				cnt--;
			}
		}
	}
	int carry = 0;
	for (int j = 0; j < max_row; j++) {
		int val1 = sums[0][j] - 48;
		int val2 = sums[1][j] - 48;
		int sum = val1 + val2 + carry;
		if (sum > 9) {
			carry = sum / 10;
			result += (sum % 10) + 48;
		}
		else {
			result += sum + 48;
			carry = 0;
		}
	}
	if (carry > 0) {
		result += carry + 48;
		carry = 0;
	}
	return result;
}

string multiply(string num1, string num2) {

	if (num1.size() == 1 && num1[0] == '0')
		return "0";
	if (num2.size() == 1 && num2[0] == '0')
		return "0";

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string result;

	vector<string> sums;

	for (int i = 0; i < num1.size(); i++) {
		string temp;
		int n1 =  num1[i] -48;
		int carry = 0;

		if (i > 0) {
			int cnt = i;
			while (cnt >0) {
				temp += 0 + 48;
				cnt--;
			}
		}
		for (int j = 0; j < num2.size(); j++) {
			int n2 =  num2[j]- 48;
			int val = n1 * n2 + carry;
			
			if (val > 9) {
				carry = val / 10;
				temp += (val % 10) + 48;
			}
			else {
				temp += val + 48;
				carry = 0;
			}
			
		}
		if (carry > 0) {
			temp += carry + 48;
			carry = 0;
		}
		sums.push_back(temp);
		if (i > 0) {
			string resInter = add_strings(sums);
			sums.clear();
			sums.push_back(resInter);
		}
		
	}

	reverse(sums[0].begin(), sums[0].end());
	// remove trailing zeros
	for (int i = 0; i < sums[0].length(); i++) {
		while (sums[0][i] == 0) {
			sums[0].erase((sums[0].begin() + i));
		}
	}
	return sums[0];

}



string addBinary(string a, string b) {

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int lenA = a.length(), lenB = b.length();
	string result;
	bool flagA = false;
	int max_row;
	if (lenA > lenB) {
		max_row = lenA;
	}
	else {
		max_row = lenB;
		flagA = true;
	}

	if (flagA) {
		int cnt = max_row - lenA;
		while (cnt > 0) {
			a += 0 + 48;
			cnt--;
		}
	}
	else {

		int cnt = max_row - lenB;
		while (cnt > 0) {
			b += 0 + 48;
			cnt--;
		}

	}

	int carry = 0;
	for (int j = 0; j < max_row; j++) {
		int val1 = a[j] - 48;
		int val2 = b[j] - 48;
		int sum = val1 + val2 + carry;
		if (sum > 1) {
			carry = sum / 2;
			result += (sum % 2) + 48;
		}
		else {
			result += sum + 48;
			carry = 0;
		}
	}
	if (carry > 0) {
		result += carry + 48;
		carry = 0;
	}

	reverse(result.begin(), result.end());
	return result;


}

#include <algorithm>

void printVector1D( vector<int> vec) {
	for (int i : vec) {
		cout << i << " ";
	}
}
vector<int> KMP_LPS(string pat) {

	int len = pat.length();
	vector <int > LPS(len);
	int i = 1, j =0;
	LPS[0] = 0;

	while (i < len) {
		if (pat[i] == pat[j]) {
			LPS[i] = j + 1;
			i++;
			j++;
		}
		else {
			if (j != 0) {
				j = LPS[j - 1];
			}
			else {
				LPS[i] = 0;
				i++;
			}
		}
	}
	return LPS;
}

string shortestPalindrome(string s) {

	string revS = s;
	reverse(revS.begin(), revS.end());

	string combin = s + '#' + revS ;

	vector <int> LPS = KMP_LPS( combin );

	return revS.substr(0, s.length() - LPS[combin.length() - 1]) + s;



}


int jump(vector<int>& nums) {
	int size = nums.size();
	vector<int> minJump(size);

	for (int i = size - 1; i >= 0; i--) {

		if (nums[i] >= size - 2 - i)
			minJump[i] = 1;
		else {
			int val = nums[i];
			int minVal = INT_MAX;

			while (i + val >= i && i + val < size-1) {
				if (minJump[i] < minVal) {
					minVal = minJump[i];
				}
				val--;
			}
			minJump[i] = minVal + 1;
		}
	}

	return minJump[size - 1];

}

int main() {
	//int n = 22113;
	//int myints[] = { 2,3,6,7};
	//std::vector<int> myvector(myints, myints + 4);
	//int i = 0;
	//combinationSum(myvector, 7);
	//cout << countAndSay(3) << endl; // prints !!!Hello World!!!
	//cout << addBinary("1010", "1011") << endl;
	 
	//printVector1D(KMP_LPS("abab"));
	vector<int> val{ 2,1,5,8,7,9,4,2,3,6,7,8};

	cout << jump(val) << endl;


	return 0;
}
