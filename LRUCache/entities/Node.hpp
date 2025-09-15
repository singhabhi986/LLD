template <typename K, typename V>

class Node {
    K key;
    V value;
public:
    Node(const K& k, const V& v) : key(k), value(v) {}
    K getKey() const { return key; }
    V getValue() const { return value; }
    Node<K,V>* prev = nullptr;
    Node<K,V>* next = nullptr;
};