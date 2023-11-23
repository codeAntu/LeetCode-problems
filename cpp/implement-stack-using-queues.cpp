#include "iostream"
#include "map"
#include "math.h"
#include "queue"
#include "vector"
using namespace std;

class MyStack {
  public:
   queue<int> q;
   MyStack() {
   }

   void push(int x) {
      q.push(x);
      int n = q.size();
      for (int i = 0; i < n - 1; i++) {
         q.push(q.front());
         q.pop();
      }
   }

   int pop() {
      int num = q.front();
      q.pop();
      return num;
   }

   int top() {
      return q.front();
   }

   bool empty() {
      return q.empty();
   }
};

int main() {
   return 0;
}
