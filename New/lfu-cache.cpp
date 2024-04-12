#include <unordered_map>
#include "math.h"

using namespace std;

class LFUCache {
private:
  struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node(int key, int val) : key(key), val(val), freq(1), prev(nullptr), next(nullptr) {}
  };
 
  struct List {
    Node *head, *tail;
    List() {
      head = new Node(0, 0);
      tail = new Node(0, 0);
      head->next = tail;
      tail->prev = head;
    }

    void insert(Node *node) {
      node->next = head->next;
      node->prev = head;
      head->next->prev = node;
      head->next = node;
    }

    void remove(Node *node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }

    bool empty() { return head->next == tail; }
  };

  int capacity, size, minFreq;
  unordered_map<int, Node *> keyToNode;
  unordered_map<int, List *> freqToList;

  void increaseFreq(Node *node) {
    int freq = node->freq;
    freqToList[freq]->remove(node);
    if (freqToList[freq]->empty() && freq == minFreq) {
      minFreq++;
    }
    node->freq++;
    if (freqToList.find(node->freq) == freqToList.end()) {
      freqToList[node->freq] = new List();
    }
    freqToList[node->freq]->insert(node);
  }

public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
    minFreq = 1;
    keyToNode.clear();
    freqToList.clear();
    freqToList[1] = new List();
  }

  int get(int key) {
    if (keyToNode.find(key) == keyToNode.end()) {
      return -1;
    }
    Node *node = keyToNode[key];
    increaseFreq(node);
    return node->val;
  }

  void put(int key, int value) {
    if (capacity == 0) {
      return;
    }
    if (keyToNode.find(key) != keyToNode.end()) {
      Node *node = keyToNode[key];
      node->val = value;
      increaseFreq(node);
    } else {
      if (size == capacity) {
        Node *node = freqToList[minFreq]->tail->prev;
        keyToNode.erase(node->key);
        freqToList[minFreq]->remove(node);
        size--;
      }
      Node *node = new Node(key, value);
      keyToNode[key] = node;
      freqToList[1]->insert(node);
      minFreq = 1;
      size++;
    }
  }
};

int main() { return 0; }