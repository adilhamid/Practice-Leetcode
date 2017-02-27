class Solution {
public:
       int findMinMoves(vector<int>& machines) {
        int totalDresses = 0, size = machines.size();
        for (auto i = 0; i < size; ++i) totalDresses += machines[i];
        if (totalDresses % size != 0) return -1;
        
        auto targetDresses = totalDresses / size, totalMoves = 0, ballance = 0;
        for (auto i = 0; i < size; ++i) {
            ballance += machines[i] - targetDresses;
            totalMoves = max(totalMoves, max(machines[i] - targetDresses, abs(ballance)));
        }
        return totalMoves;
    }
};