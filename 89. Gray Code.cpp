 vector<int> grayCode(int n) {
        
        if(!n) return {0};
        
        int combin = pow(2,n);
        vector<int>result(combin);
        int grayCode;
        for(int i = combin-1; i>=0; i--){
             grayCode = i ^ (i/2);
            result[i] = grayCode;
        }
        
        return result;
    }