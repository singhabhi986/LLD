#include "entities/DLL.hpp"
#include <unordered_map>

template <typename K, typename V>
class LRUCache {
    int capacity;
    DLL<K,V> dll;
    std::unordered_map<K, Node<K,V>*> map;
public:
    LRUCache(int cap) : capacity(cap) {}
    V get(const K& key);
    void put(const K& key, const V& value);
};