class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        int len = A.size();
        if(!len) return 0;
       
        long allsum =0;
        long sum =0;
        
        for(int i =0; i<len; i++){
            allsum += i*A[i];
            sum += A[i];
        }
       
        long result = allsum;
        
        for(int i =0; i<len; i++){
            allsum -= sum;
            allsum += A[i];
            allsum += A[i] * (len-1);
            result = max(result, allsum);
        }
        
        return result;
        
    }
};