#include <queue>
#include "math.h"
#include "vector"

using namespace std;

// class MedianFinder {
// public:
//   priority_queue<int> maxHeap;
//   priority_queue<int, vector<int>, greater<int>> minHeap;
//   bool even = true;

//   MedianFinder() {}

//   void addNum(int num) {
//     if (even) {
//       maxHeap.push(num);
//       minHeap.push(maxHeap.top());
//       maxHeap.pop();
//     } else {
//       minHeap.push(num);
//       maxHeap.push(minHeap.top());
//       minHeap.pop();
//     }

//     even = !even;
//   }

//   double findMedian() {
//     if (even) {
//       return (maxHeap.top() + minHeap.top()) / 2.0;
//     } else {
//       return minHeap.top();
//     }
//   }
// };

class MedianFinder {
public:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  MedianFinder() {}

  void addNum(int num) {
    if (maxHeap.empty()) {
      maxHeap.push(num);
      return;
    }

    if (maxHeap.size() == minHeap.size()) {
      if (num < maxHeap.top()) {
        maxHeap.push(num);
      } else {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
    } else {
      if (num > maxHeap.top()) {
        minHeap.push(num);
      } else {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
    }
  }

  double findMedian() {
    if(maxHeap.size() == minHeap.size()) {
      return (maxHeap.top() + minHeap.top()) / 2.0;
    } else {
      return maxHeap.top();
    }
  }
};

int main() { return 0; }