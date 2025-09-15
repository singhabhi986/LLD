#include "LRUCache.hpp"

template <typename K, typename V>

V LRUCache<K, V>::get(const K &key)
{
    if (map.find(key) == map.end())
    {
        throw std::runtime_error("Key not found");
    }
    Node<K, V> *node = map[key];
    dll.update(node);
    return node->getValue();
}

template <typename K, typename V>
void LRUCache<K, V>::put(const K &key, const V &value)
{
    bool keyExists = map.find(key) != map.end();
    if (keyExists)
    {
        dll.update(map[key]);
        return;
    }

    // check if we need to evict
    if (map.size() >= capacity)
    {
        Node<K, V> *lruNode = dll.tail->prev;
        if (lruNode != dll.head)
        { // Ensure we are not trying to remove sentinel node
            K lruKey = lruNode->getKey();
            dll.removeLast();
            map.erase(lruKey);
        }
    }

    Node<K, V> *newNode = new Node<K, V>(key, value);
    dll.addToFront(newNode);
}