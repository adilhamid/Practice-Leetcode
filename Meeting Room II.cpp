bool myComp(const Interval &a, const Interval &b){
    return (a.start<b.start);
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int rooms = 0;
        priority_queue<int> pq;//prioritize earlier ending time
        sort(intervals.begin(), intervals.end(), myComp);
        for(int i=0; i<intervals.size(); ++i){
            while(!pq.empty() && -pq.top()<intervals[i].end) pq.pop();
            pq.push(-intervals[i].end);
            rooms = max(rooms, (int)pq.size());
        }
        return rooms;
    }
};


///////////////////////////////////////////////////////////////////////////////



class Solution { 
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> rooms;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            int idx = findNonOverlapping(rooms, intervals[i]);
            if (rooms.empty() || idx == -1)
                rooms.push_back(intervals[i]);
            else rooms[idx] = intervals[i];
        }
        return (int)rooms.size();
    } 
private:
    static bool compare(Interval& interval1, Interval& interval2) {
        return interval1.start < interval2.start;
    }
    int findNonOverlapping(vector<Interval>& rooms, Interval& interval) {
        int n = rooms.size();
        for (int i = 0; i < n; i++)
            if (interval.start >= rooms[i].end)
                return i;
        return -1;
    }
};