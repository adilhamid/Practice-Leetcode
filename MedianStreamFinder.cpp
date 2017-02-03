#include"import.h"
using namespace std;
/*
class MedianFinder {

private:

priority_queue<int,  std::vector<int>, greater<int> > minHeap;
priority_queue<int> maxHeap;
int sizeMin, sizeMax;

public:
    
    MedianFinder() {
        sizeMin=0; 
        sizeMax=0;
    }
    
    void getBalance(){    
        if(sizeMax>sizeMin+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            sizeMin++;sizeMax--;
        }
        else if (sizeMin>sizeMax+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            sizeMin--;sizeMax++;   
        }
    }
    void addNum(int num) {
        if (sizeMax==0) {
            minHeap.push(num); sizeMin++;
        }
        else if (sizeMin==0){
            maxHeap.push(num); sizeMax++;
        }
        else{
            if (num<maxHeap.top()){
                maxHeap.push(num); sizeMax++;
            }
            else{
                minHeap.push(num); sizeMin++;
            }
        }
        getBalance();
    }
    
    double findMedian() {
       if(sizeMin==sizeMax){
           return (double) (minHeap.top() + maxHeap.top())/2;
       }
       else if(sizeMin>sizeMax){
           return minHeap.top();
       }
       else{
            return maxHeap.top();
       }
    }
};
*/
vector<vector<int>> visitedMat;

int main() {
	visitedMat.resize(10, vector<int>(10, -1));
	for (auto num : visitedMat) {
		for (auto val : num)
			cout << val << " ";
		cout << endl;
	}
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */