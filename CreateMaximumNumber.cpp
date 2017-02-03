
#include "import.h"


using namespace std;


class Solution{
public:
	vector<int> maxNumber(vector<int> nums, int k) {
		int drop = nums.size() - k;
		vector<int> out;
		for (int num : nums) {
			while (drop && out.size() && out.back() < num) {
				out.pop_back();
				drop--;
			}
			out.push_back(num);
		}
		out.resize(k);
		return out;
	}
	vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
		vector<int> out;
		auto i1 = nums1.begin(), end1 = nums1.end();
		auto i2 = nums2.begin(), end2 = nums2.end();
		while (i1 != end1 || i2 != end2)
			out.push_back(lexicographical_compare(i1, end1, i2, end2) ? *i2++ : *i1++);
		return out;
	}

	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int len1 = nums1.size(), len2 = nums2.size();
		vector<int> best;
		for (int k1 = max(k - len2, 0); k1 <= min(k, len1); ++k1) {
			best = max(best, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k - k1)));	
		}
		return best;
	}
	
};

int main() {
	Solution obj;
	vector<int> mynumber({ 9,1,2,5,8,3 });
	vector<int> result = obj.maxNumber(mynumber, 4);
	for (int num : result)
		cout << num << " ";

	return 0;
}