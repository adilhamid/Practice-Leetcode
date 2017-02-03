class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        unordered_map<string, vector<int>> dpMap;
        return computeWithDp(input, dpMap);
        
    }
    
    vector<int> computeWithDp(string input, unordered_map<string, vector<int>> &dpMap){
      vector<int> result ;
      int size = input.size();
      
      for(int i =0; i< size; i++){
        char curr = input[i];
        if(curr == '+' || curr == '-' || curr == '*'){
          vector<int> result1, result2;
          string substr = input.substr(0,i);
          
          if(dpMap.find(substr) != dpMap.end())
            result1 = dpMap[substr];
          else
            result1 = computeWithDp(substr,dpMap);
          
          // Now the second part of the code
          substr = input.substr(i+1);
          
          if(dpMap.find(substr) !=dpMap.end())
            result2 = dpMap[substr];
          else
            result2 = computeWithDp(substr,dpMap);
          
          for(auto n1: result1)
            for(auto n2:result2){
              if(curr == '+')
                result.push_back(n1 + n2);
              else if(curr == '-')
                result.push_back(n1-n2);
              else if(curr == '*')
                result.push_back(n1*n2);
              else{
                cout << "Error Operator"<<endl;
                exit(0); // Error case
              }                
              
            }
        }
        
        
      }
      
      if(result.empty()){
          cout << stoi(input)<<endl;
          result.push_back(stoi(input));
        }
        
        dpMap[input] = result;
        return result;
        
        
    }
};