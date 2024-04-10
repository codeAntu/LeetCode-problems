#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "iostream"

using namespace std;

class TimeMap {
public:
  unordered_map<string, vector<pair<string, int>>> map;
  TimeMap() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout.tie(0);
  }

  void set(string key, string value, int timestamp) { map[key].push_back({value, timestamp}); }

  string get(string key, int timestamp) {
    if (!map.count(key)) {
      return "";
    }

    auto& values = map[key];
    string res = "";
    int left = 0;
    int right = values.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (values[mid].second == timestamp) {
        return values[mid].first;
      } else if (values[mid].second < timestamp) {
        res = values[mid].first;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return res;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
  Solution s;

  return 0;
}