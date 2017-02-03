/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {

private:
    struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };
    set<Interval, Cmp> SumRab;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {
                
    }
    
    void addNum(int val) {
        auto it = SumRab.lower_bound(Interval(val, val));
        int start = val, end = val;
        if(it != SumRab.begin() && (--it)->end+1 < start) it++;
        while(it != SumRab.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = SumRab.erase(it);
        }
        SumRab.insert(it,Interval(start, end));
       
        
    }
    
    vector<Interval> getIntervals() {
        return (vector<Interval>(SumRab.begin(),SumRab.end()));
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */