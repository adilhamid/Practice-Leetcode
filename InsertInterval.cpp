
class Solution {
public:
	vector<Interval> insertON(vector<Interval>& intervals, Interval newInterval) {

		int len = intervals.size();

		if (!len) {
			intervals.push_back(newInterval);
			return intervals;
		}
		int count = 0;

		if (intervals[0].start > newInterval.end)
			intervals.insert(intervals.begin(), newInterval);
		else if (intervals[len - 1].end < newInterval.start)
			intervals.push_back(newInterval);
		else {

			for (int i = 0; i < intervals.size(); i++) {
				if (intervals[i].end < newInterval.start) {
					continue;
				}
				else if (intervals[i].start > newInterval.end) {
					intervals.insert(intervals.begin() + i, newInterval);
					break;
				}
				// check if overlapping 
				else if (isOverlapping(intervals[i].start, intervals[i].end, newInterval.start, newInterval.end)) {
					newInterval.start = min(newInterval.start, intervals[i].start);
					newInterval.end = max(newInterval.end, intervals[i].end);
					intervals.erase(intervals.begin() + i);
					--i;

				}
				else {   // No Overlap Found
					break;
				}

				if (intervals.empty() || i + 1 == intervals.size()) {
					intervals.push_back(newInterval);
					return intervals;
				}
			}
		}

		return intervals;
	}
	// Here [x1,x2] and [y1,y2] are two ranges
	bool isOverlapping(int x1, int x2, int y1, int y2) {
		return max(x1, y1) <= min(x2, y2);
	}

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		
		 int len = intervals.size();

        if (!len) {
            intervals.push_back(newInterval);
            return intervals;
        }

        if (intervals[0].start > newInterval.end)
            intervals.insert(intervals.begin(), newInterval);
        else if (intervals[len - 1].end < newInterval.start)
            intervals.push_back(newInterval);
            
        
        auto it1 = lower_bound(intervals.begin(), intervals.end(), newInterval, [](const Interval& a, const Interval &b) {return a.end < b.start; });
        auto it2 = upper_bound(intervals.begin(), intervals.end(), newInterval, [](const Interval& a, const Interval &b) {return a.end < b.start; });
        
        auto it3 = (it2 == intervals.begin()) ? it2 : it2 - 1;
        Interval m((it1 == it2) ? newInterval.start : min(it1->start, newInterval.start),
            (it1 == it2) ? newInterval.end : max(it3->end, newInterval.end));
    
        if(it2 != intervals.begin())
            intervals.erase(it1, it2);
        intervals.insert(it1,m);

        return intervals;
    }

};
int main() {
	Solution obj;
	Interval temps[5];
	temps[0] = Interval(0, 2);
	temps[1] = Interval(3, 9);
	temps[2] = Interval(6, 11);
	//temps[3] = Interval(8, 10);
	//temps[4] = Interval(12, 16);

	vector<Interval> old;
	for (int i = 0; i < 2; i++) {
		old.push_back(temps[i]);
	}
	Interval newOne(6, 8);

	vector<Interval> temp = obj.insert(old, newOne);

	for (Interval i : temp) {
		cout << "[" << i.start << "," << i.end << "]" << " ,";
	}

	return 0;
}