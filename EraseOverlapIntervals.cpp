/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        
        int len = intervals.size();
        if(len<=1) return 0;
        
        sort(intervals.begin(), intervals.end(), mysort);
        
        int prevEnd = intervals[0].end; 
        int count =0;
        for(int i =1; i< len; i++){
            if(intervals[i].start < prevEnd){
                count++;
                if(intervals[i].end < prevEnd) prevEnd = intervals[i].end;
            }
            else{
                prevEnd = intervals[i].end;
            }
            
        }
        return count;
    }
    
    static bool mysort(Interval a, Interval b){
        return a.start <  b.start;
    }
};