#include "iostream"
#include "queue"
#include "unordered_map"
#include "vector"

using namespace std;

class NumberContainers {
private:
  unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndices;
  unordered_map<int, int> indexToNumber;

public:
  NumberContainers() {}

  void change(int index, int number) {
    if (indexToNumber.count(index)) {
      int prevNum = indexToNumber[index];
      if (prevNum == number) return;
      numberToIndices[prevNum].push(INT_MAX);  // Lazy deletion
    }
    numberToIndices[number].push(index);
    indexToNumber[index] = number;
  }

  int find(int number) {
    while (!numberToIndices[number].empty() &&
           indexToNumber[numberToIndices[number].top()] != number) {
      numberToIndices[number].pop();
    }
    return numberToIndices[number].empty() ? -1 : numberToIndices[number].top();
  }
};

int main() {
  NumberContainers nc;

  return 0;
}