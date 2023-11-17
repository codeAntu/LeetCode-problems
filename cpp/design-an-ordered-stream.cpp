#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class OrderedStream {
  public:
   string str[1005];
   int i = 0;
   OrderedStream(int n) {
   }

   vector<string> insert(int idKey, string value) {
      vector<string> res;
      str[idKey - 1] = value;
      while (str[i] != "") {
         res.push_back(str[i]);
         i++;
      }
      return res;
   }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {
   return 0;
}
