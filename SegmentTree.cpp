#include"import.h"

using namespace std;



void updateUtil(int *ST, int arrStart, int arrEnd, int index, int diffVal, int stIndex){
	if (index < arrStart || index>arrEnd) {
		return;
	}
	
	ST[stIndex] += diffVal;
	

	if (arrStart != arrEnd) {
		int mid = arrStart + (arrEnd - arrStart) / 2;
		updateUtil(ST, arrStart, mid, index, diffVal, 2*stIndex+1);
		updateUtil(ST, mid+1, arrEnd, index, diffVal, 2*stIndex+2);
	}
}



void updateValue(int arr[], int* ST, int size, int index, int newVal) {
	if (index <0 || index >size - 1) {
		cout << "invalid " << endl;
		return;
	}
	int diffVal = newVal - arr[index];

	arr[index] = newVal;

	updateUtil(ST, 0, size - 1, index, diffVal, 0);
}



int getSumUtil(int * ST, int stStart, int stEnd, int qStart, int qEnd, int stIndex) {
	
	if (qStart <= stStart && qEnd >= stEnd) {
		return ST[stIndex];
	}

	if (qEnd < stStart || qStart > stEnd)
		return 0;

	int mid = stStart + (stEnd - stStart) / 2;
	 
	return getSumUtil(ST, stStart, mid, qStart, qEnd, 2 * stIndex + 1) + getSumUtil(ST, mid + 1, stEnd, qStart, qEnd, 2 * stIndex + 2);
}


int getSum(int *ST, int size, int start, int end) {

	if (start < 0 || end > size-1 || start > end) {
		cout << "error " << endl;
		return -1;
	}

	return getSumUtil(ST, 0, size - 1, start, end, 0);

}

//Construct Util for Segement Tree
int constructSTUtil(int *arr, int start, int end, int *ST, int indexST) {
	if (start == end) {
		ST[indexST] = arr[start];
		return ST[indexST];
	}
	int mid = start + (end - start) / 2;
	ST[indexST] = constructSTUtil(arr, start, mid, ST, 2 * indexST + 1) + 
						constructSTUtil(arr, mid+1, end, ST, 2 * indexST + 2);

	return ST[indexST];

}



int * constructST(int *arr, int num) {
	//First Calculate the memory needed for new Segment Tree
	int intNodes = (int)ceil(log2(num));

	//Total Nodes
	int totalNodes = 2 * (int)pow(2, intNodes) - 1;

	//Allocating the Memory
	int *ST = new int[totalNodes];

	//Now Fill the values using the constructUtil

	constructSTUtil(arr, 0, num - 1, ST, 0);

	return ST;

}


int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };

	int len = sizeof(arr) / sizeof(arr[0]);

	int *ST = constructST(arr, len);

	//Print the Sum Values
	cout << getSum(ST, len, 1, 2)<<endl;
	updateValue(arr, ST, len, 2, 0);
	cout << getSum(ST, len, 1, 2) << endl;
}