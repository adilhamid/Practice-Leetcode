class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int gasStations = gas.size();
        if(!gasStations) return -1;
        
        // Determine the maximum Gas savings that is gas[i] - cost[i] is highest. we will start with that index .
        int remGas = 0;
        int maxGas = INT_MIN; //remGas; 
        
        int highestProfitP = -1;
        bool flagSet = false;
        
        for(int i =0 ;i<gasStations; i++){
            
            int tempVal = gas[i]-cost[i];
            remGas += tempVal;
            
            if(remGas < 0){
                flagSet = true;
                if(abs(remGas) >= maxGas)
                    {
                        maxGas = abs(remGas);
                        highestProfitP = i+1;
                    }
            }
        }
        
        if(flagSet){
            if(remGas >=0 ) return highestProfitP;
            else return -1;
        }
        return 0;
    }
};