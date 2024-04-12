#include <float.h>
#include <unordered_map>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"


using namespace std;

struct Node {
  int key;
  int value;
  Node* prev;
  Node* next;
  Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
  unordered_map<int, Node *> cache;
  Node* head;
  Node* tail;
  int capacity;
  int size;

  void remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  void add(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }   

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (cache.find(key) == cache.end()) return -1;
    Node* node = cache[key];
    remove(node);
    add(node);
    return node->value;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      Node* node = cache[key];
      node->value = value;
      remove(node);
      add(node);
    } else {
      Node* node = new Node(key, value);
      cache[key] = node;
      add(node);
      size++;
      if (size > capacity) {
        Node* node = tail->prev;
        remove(node);
        cache.erase(node->key);
        size--;
      }
    }
  }
};

int main() {

  return 0;
}