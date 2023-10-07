#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include"unordered_set"
using namespace std;

class Solution {
public:
   bool uniqueOccurrences(vector<int>& arr) {

      unordered_set<int> s;
      for (int n : arr) {
         if (s.find(n) != s.end()) s.insert(n);
         else return true;
      }
      return false;
   }
};

// by @codeAbinash
// Time : O(n)
// Space : O(n)

#include "vector"
#include "unordered_map"
using namespace std;

class Solution {
public:
   bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int, int> m;
      unordered_set <int> s;
      
      for (auto n : arr) m[n]++;
      for(auto x : m) s.insert(x.second);

      return m.size() == s.size();
   }
};


















int main() {
   Solution s;


   return 0;
}