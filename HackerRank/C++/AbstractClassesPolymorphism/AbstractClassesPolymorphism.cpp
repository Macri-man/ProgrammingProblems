#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class Cache {
protected:
    unordered_map<int, Node*> mp;
    int cp;
    Node* head;
    Node* tail;

public:
    Cache(int capacity) {
        cp = capacity;
        head = nullptr;
        tail = nullptr;
    }

    virtual void set(int key, int value) = 0;
    virtual int get(int key) = 0;
};

class LRUCache : public Cache {
public:
    LRUCache(int capacity) : Cache(capacity) {}

    void set(int key, int value) override {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            if (mp.size() == cp) {
                mp.erase(tail->key);
                removeNode(tail);
            }
            addToHead(newNode);
            mp[key] = newNode;
        }
    }

    int get(int key) override {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

private:
    void addToHead(Node* node) {
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = head;
    }

    void removeNode(Node* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;

        delete node;
    }

    void moveToHead(Node* node) {
        if (node == head) return;
        removeNodeWithoutDelete(node);
        addToHead(node);
    }

    void removeNodeWithoutDelete(Node* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
    }
};



int main() {
    int N, capacity;
    cin >> N >> capacity;
    LRUCache cache(capacity);
    
    string command;
    for (int i = 0; i < N; ++i) {
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << cache.get(key) << endl;
        } else if (command == "set") {
            int key, value;
            cin >> key >> value;
            cache.set(key, value);
        }
    }
    return 0;
}

