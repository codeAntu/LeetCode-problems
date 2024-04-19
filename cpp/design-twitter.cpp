#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

#include "math.h"
#include "vector"

using namespace std;

class Twitter {
public:
  unordered_map<int, vector<pair<int, int>>> tweets;
  unordered_map<int, unordered_set<int>> followers;
  int time = 0;

  Twitter() {}

  void postTweet(int userId, int tweetId) { tweets[userId].push_back({time++, tweetId}); }

  vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>> pq;
    int size = tweets[userId].size();
    for (int i = 0; i < 10; i++) {
      if (size - i - 1 >= 0) pq.push(tweets[userId][size - i - 1]);
    }

    if (followers.find(userId) != followers.end()) {
      for (int followee : followers[userId]) {
        size = tweets[followee].size();
        for (int i = 0; i < 10; i++) {
          if (size - i - 1 >= 0) pq.push(tweets[followee][size - i - 1]);
        }
      }
    }
    vector<int> res;
    while (!pq.empty() && res.size() < 10) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }

  void follow(int followerId, int followeeId) { followers[followerId].insert(followeeId); }

  void unfollow(int followerId, int followeeId) {
    if (followers.find(followerId) == followers.end() ||
        followers[followerId].find(followeeId) == followers[followerId].end())
      return;
    followers[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

