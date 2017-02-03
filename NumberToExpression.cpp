#include "import.h"

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        unordered_map<string, int> dpMap;
        vector<string> result = computeWithDp(num, dpMap);
        
		for (string str : result) {
			if(dpMap[str] == target)
				cout << str << " = " << dpMap[str] << endl;
		}
            
		return {} ;
    }

    vector<string> computeWithDp(string input, unordered_map<string, int> &dpMap){
     
      vector<string> result;
      
	  int size = input.size();

	  if (size == 1) {
		  result.push_back(input);
		  return result;
	  }
      
      for(int i =1; i< size; i++){
        
        vector<string> result1, result2;
        
        string curr = input.substr(0,i);

		if (curr.length()>1) {
			result1 = computeWithDp(curr, dpMap);
		}
		else {
			dpMap[curr] = stoi(curr);
			result1.push_back(curr);
		}

        string substr = input.substr(i);
         
         if(substr.length()>1){
             result2 = computeWithDp(substr, dpMap);
         }
		 else {
			 dpMap[substr] = stoi(substr);
			 result2.push_back(substr);
		 }

		 for(string str1 : result1)
			 for (string str2 : result2) {
				
				 result.push_back("(" + str1 + "+" + str2 + ")");
				 dpMap["(" + str1 + "+" + str2 + ")"] = dpMap[str1] + dpMap[str2];

				 result.push_back("(" + str1 + "-" + str2 + ")");
				 dpMap["(" + str1 + "-" + str2 + ")"] = dpMap[str1] - dpMap[str2];

				 result.push_back("(" + str1 + "*" + str2 + ")");
				 dpMap["(" + str1 + "*" + str2 + ")"] = dpMap[str1] * dpMap[str2];
				
			 }
      }
        return result;
    }
};


int main() {
	Solution obj;

	obj.addOperators("232", 8);

	return 0;
}